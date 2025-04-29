#include "CADWire.h"

#include "TopAbs2String.h"

#include <BRepTools_ShapeSet.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Wire.hxx>

namespace Library
{
    CADWire::CADWire() {}
    CADWire::~CADWire() {}

    std::string CADWire::toString() const
    {
        std::stringstream ss;
        ss << "Wire";
        bool isClosed = BRep_Tool::IsClosed(TopoDS::Wire(getData()));
        if (isClosed)
            ss << ", C";
        std::string result = ss.str();
        return result;
    }

    std::string CADWire::getType() const
    {
        return TopAbs2String(TopAbs_WIRE);
    }

    TopoDS_Wire& CADWire::get()
    {
        return (TopoDS_Wire&)getData();
    }

    const TopoDS_Wire& CADWire::get() const
    {
        return (const TopoDS_Wire&)getData();
    }
}