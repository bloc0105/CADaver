#include "CADCompSolid.h"

#include "TopAbs2String.h"

#include <TopAbs_ShapeEnum.hxx>
#include <BRepTools_ShapeSet.hxx>
#include <TopoDS_CompSolid.hxx>

namespace Library
{
    CADCompSolid::CADCompSolid() {}

    CADCompSolid::~CADCompSolid() {}

    std::string CADCompSolid::getType() const
    {
        return TopAbs2String(TopAbs_COMPSOLID);
    }

    std::string CADCompSolid::toString() const
    {
        std::stringstream  ss;
        BRepTools_ShapeSet shapeSet;
        shapeSet.Add(getData());
        ss << "CompSolid (" << shapeSet.NbShapes() << " solid)";
        std::string result = ss.str();
        return result;
    }

    TopoDS_CompSolid& CADCompSolid::get()
    {
        return (TopoDS_CompSolid&)getData();
    }

    const TopoDS_CompSolid& CADCompSolid::get() const
    {
        return (const TopoDS_CompSolid&)getData();
    }
}