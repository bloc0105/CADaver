#include "CADShape.h"

#include <stdexcept>

#include "CADShapeFactory.h"
#include "TopAbs2String.h"

#include <STEPControl_Writer.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopoDS_Compound.hxx>
#include <TopoDS_Iterator.hxx>

namespace Library
{
    CADShape::CADShape()
    {
        data = std::make_unique<TopoDS_Compound>();
    }

    CADShape ::~CADShape() {}

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
            auto current = CADShapeFactory::make(std::make_unique<TopoDS_Shape>(it.Value()));
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
    void CADShape::setData(std::unique_ptr<TopoDS_Shape> d)
    {
        data = std::move(d);
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
