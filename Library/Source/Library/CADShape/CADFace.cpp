#include "CADFace.h"

#include "TopAbs2String.h"

#include <BRepTools_ShapeSet.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <GProp_GProps.hxx>
#include <BRepGProp.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Face.hxx>

namespace Library
{
    CADFace::CADFace() {}
    CADFace::~CADFace() {}

    std::string CADFace::toString() const
    {
        std::stringstream ss;
        GProp_GProps props;
        BRepGProp::SurfaceProperties(TopoDS::Face(getData()), props);
        ss << "Face, A=" << std::fixed << std::setprecision(2) << props.Mass();
        bool isClosed = BRep_Tool::IsClosed(TopoDS::Face(getData()));
        if (isClosed)
            ss << ", C";
        std::string result = ss.str();
        return result;
    }

    std::string CADFace::getType() const
    {
        return TopAbs2String(TopAbs_FACE);
    }

    TopoDS_Face& CADFace::get()
    {
        return (TopoDS_Face&)getData();
    }

    const TopoDS_Face& CADFace::get() const
    {
        return (const TopoDS_Face&)getData();
    }
}