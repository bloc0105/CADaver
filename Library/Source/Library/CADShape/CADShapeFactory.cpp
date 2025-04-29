#include "CADShapeFactory.h"

#include "CADCompSolid.h"
#include "CADCompound.h"
#include "CADEdge.h"
#include "CADFace.h"
#include "CADShell.h"
#include "CADSolid.h"
#include "CADVertex.h"
#include "CADWire.h"

#include <STEPControl_Reader.hxx>
#include <TopoDS_Compound.hxx>
#include <TopAbs_ShapeEnum.hxx>

namespace Library
{
    std::unique_ptr<CADShape> CADShapeFactory::make(const std::string& filename)
    {
        STEPControl_Reader    reader;
        IFSelect_ReturnStatus status = reader.ReadFile(filename.c_str());

        if (status != IFSelect_RetDone)
            return nullptr;
        reader.TransferRoots();
        return make(std::make_unique<TopoDS_Shape>(reader.OneShape()));
    }

    std::unique_ptr<CADShape> CADShapeFactory::make(int t)
    {
        TopAbs_ShapeEnum          type = (TopAbs_ShapeEnum)t;
        std::unique_ptr<CADShape> result;
        switch (type)
        {
            case TopAbs_COMPOUND:
                result = std::make_unique<CADCompound>();
                break;
            case TopAbs_COMPSOLID:
                result = std::make_unique<CADCompSolid>();
                break;
            case TopAbs_SOLID:
                result = std::make_unique<CADSolid>();
                break;
            case TopAbs_SHELL:
                result = std::make_unique<CADShell>();
                break;
            case TopAbs_FACE:
                result = std::make_unique<CADFace>();
                break;
            case TopAbs_WIRE:
                result = std::make_unique<CADWire>();
                break;
            case TopAbs_EDGE:
                result = std::make_unique<CADEdge>();
                break;
            case TopAbs_VERTEX:
                result = std::make_unique<CADVertex>();
                break;
            case TopAbs_SHAPE:
                result = std::make_unique<CADShape>();
                break;
            default:
                return nullptr;
        }
        return std::move(result);
    }
    std::unique_ptr<CADShape> CADShapeFactory::make(std::unique_ptr<TopoDS_Shape> data)
    {
        auto result = make(data->ShapeType());
        result->setData(std::move(data));
        return std::move(result);
    }

}