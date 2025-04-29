#include "CADEdge.h"

#include "TopAbs2String.h"

#include <TopAbs_ShapeEnum.hxx>
#include <BRepTools_ShapeSet.hxx>
#include <TopoDS_Edge.hxx>

namespace Library
{
    CADEdge::CADEdge() {}
    CADEdge::~CADEdge() {}

    std::string CADEdge::toString() const
    {
        return getType();
    }

    std::string CADEdge::getType() const
    {
        return TopAbs2String(TopAbs_EDGE);
    }

    TopoDS_Edge& CADEdge::get()
    {
        return (TopoDS_Edge&)getData();
    }

    const TopoDS_Edge& CADEdge::get() const
    {
        return (const TopoDS_Edge&)getData();
    }
}