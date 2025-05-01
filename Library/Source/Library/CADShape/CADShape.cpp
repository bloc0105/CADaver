#include "CADShape.h"

#include <stdexcept>

#include "CADShapeFactory.h"
#include "TopAbs2String.h"

#include <Poly_Triangulation.hxx>
#include <STEPControl_Writer.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopLoc_Location.hxx>
#include <TopoDS_Compound.hxx>
#include <TopoDS_Iterator.hxx>
#include <TopoDS_Shape.hxx>

namespace Library
{
    CADShape::CADShape()
    {
        data = std::make_unique<TopoDS_Shape>();
    }

    CADShape::~CADShape() {}

    std::string CADShape::toString() const
    {
        return getType();
    }

    std::string CADShape::getType() const
    {
        return TopAbs2String(TopAbs_SHAPE);
    }

    std::vector<std::unique_ptr<CADShape>> CADShape::getChildren() const
    {
        std::vector<std::unique_ptr<CADShape>> result;
        TopoDS_Iterator                        it(getData(), true, false);

        while (it.More())
        {
            auto current = CADShapeFactory::make(it.Value());
            it.Next();
            result.push_back(std::move(current));
        }
        return result;
    }

    TopoDS_Shape& CADShape::getData()
    {
        return *data;
    }

    const TopoDS_Shape& CADShape::getData() const
    {
        return *data;
    }
    void CADShape::setData(const TopoDS_Shape& d)
    {
        data = std::make_unique<TopoDS_Shape>(d);
    }

    bool CADShape::save(const std::string& filename) const
    {
        // https://dev.opencascade.org/content/export-multi-shapes-single-step-file
        STEPControl_Writer    aWriter;
        IFSelect_ReturnStatus aStat = aWriter.Transfer(*data, STEPControl_AsIs);
        aStat                       = aWriter.Write(filename.c_str());
        if (aStat != IFSelect_RetDone)
            return false;
        return true;
    }

    std::unique_ptr<CADShape> CADShape::load(const std::string& filename)
    {
        std::unique_ptr<CADShape> result = CADShapeFactory::make(filename);
        return std::move(result);
    }
}
