#include "CADShape.h"

#include "TopAbs2String.h"

#include <BRepGProp.hxx>
#include <BRepTools_ShapeSet.hxx>
#include <BRep_Builder.hxx>
#include <GProp_GProps.hxx>
#include <STEPControl_Reader.hxx>
#include <STEPControl_Writer.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Compound.hxx>
#include <TopoDS_Iterator.hxx>

namespace Library
{
    CADShape::CADShape()
    {
        data = std::make_unique<TopoDS_Compound>();
    }

    CADShape::~CADShape() {}

    bool CADShape::save(const std::string& filename) const
    {
        // https://dev.opencascade.org/content/export-multi-shapes-single-step-file
        STEPControl_Writer    aWriter;
        IFSelect_ReturnStatus aStat = aWriter.Transfer(*data, STEPControl_AsIs);
        aStat                       = aWriter.Write("bottle.stp");
        if (aStat != IFSelect_RetDone)
            return false;
        return true;
    }

    bool CADShape::load(const std::string& filename)
    {
        STEPControl_Reader    reader;
        IFSelect_ReturnStatus status = reader.ReadFile(filename.c_str());

        if (status != IFSelect_RetDone)
            return false;
        reader.TransferRoots();
        *data = reader.OneShape();
        return true;
    }

    std::vector<std::unique_ptr<CADShape>> CADShape::getChildren() const
    {
        std::vector<std::unique_ptr<CADShape>> result;
        TopoDS_Iterator                        it(*data, true, false);

        while (it.More())
        {
            std::unique_ptr<CADShape> current = std::make_unique<CADShape>();
            *current->data                    = it.Value();
            it.Next();
            result.push_back(std::move(current));
        }
        return result;
    }

    std::string CADShape::getType() const
    {
        return TopAbs2String(data->ShapeType());
    }

    std::string CADShape::toString() const
    {
        std::stringstream ss;
        switch (data->ShapeType())
        {
            case TopAbs_COMPOUND:
            {
                BRepTools_ShapeSet shapeSet;
                shapeSet.Add(*data);
                ss << "Compound (" << shapeSet.NbShapes() << " sub)";
                break;
            }
            case TopAbs_COMPSOLID:
            {
                BRepTools_ShapeSet shapeSet;
                shapeSet.Add(*data);
                ss << "CompSolid (" << shapeSet.NbShapes() << " solid)";
                break;
            }
            case TopAbs_SOLID:
            {
                GProp_GProps props;
                BRepGProp::VolumeProperties(TopoDS::Solid(*data), props);
                ss << "Solid, V=" << std::fixed << std::setprecision(2) << props.Mass();
                break;
            }
            case TopAbs_SHELL:
            {
                BRepTools_ShapeSet shapeSet;
                shapeSet.Add(*data);
                ss << "Shell (" << shapeSet.NbShapes() << " face)";
                break;
            }
            case TopAbs_FACE:
            {
                GProp_GProps props;
                BRepGProp::SurfaceProperties(TopoDS::Face(*data), props);
                ss << "Face, A=" << std::fixed << std::setprecision(2) << props.Mass();
                bool isClosed = BRep_Tool::IsClosed(TopoDS::Face(*data));
                if (isClosed)
                    ss << ", C";
                break;
            }
            case TopAbs_WIRE:
            {
                ss << "Wire";
                bool isClosed = BRep_Tool::IsClosed(TopoDS::Wire(*data));
                if (isClosed)
                    ss << ", C";
                break;
            }
            case TopAbs_EDGE:
            {
                GProp_GProps props;
                ss << "Edge";
                break;
            }
            case TopAbs_VERTEX:
            {
                gp_Pnt p = BRep_Tool::Pnt(TopoDS::Vertex(*data));
                ss << "Vertex (" << std::fixed << std::setprecision(1) << p.X() << "," << std::fixed << std::setprecision(1) << p.Y() << "," << std::fixed << std::setprecision(1) << p.Z() << ")";
                break;
            }
            case TopAbs_SHAPE:
                ss << "Shape";
                break;
            default:
                ss << "Unknown";
                break;
        }
        std::string result = ss.str();
        return result;
    }
}