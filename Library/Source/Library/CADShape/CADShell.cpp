#include "CADShell.h"

#include "TopAbs2String.h"

#include <BRepTools_ShapeSet.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopoDS_Shell.hxx>

namespace Library
{
    CADShell::CADShell() {}
    CADShell::~CADShell() {}

    std::string CADShell::toString() const
    {
        std::stringstream  ss;
        BRepTools_ShapeSet shapeSet;
        shapeSet.Add(getData());
        ss << "Shell (" << shapeSet.NbShapes() << " face)";
        std::string result = ss.str();
        return result;
    }

    std::string CADShell::getType() const
    {
        return TopAbs2String(TopAbs_SHELL);
    }

    TopoDS_Shell& CADShell::get()
    {
        return (TopoDS_Shell&)getData();
    }

    const TopoDS_Shell& CADShell::get() const
    {
        return (const TopoDS_Shell&)getData();
    }
}