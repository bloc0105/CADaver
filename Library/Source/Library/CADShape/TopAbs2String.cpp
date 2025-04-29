#include "TopAbs2String.h"

#include <TopAbs_ShapeEnum.hxx>

int String2TopAbs(const std::string& type)
{
    if (type == "TopAbs_COMPOUND")
        return (int)TopAbs_COMPOUND;
    else if (type == "TopAbs_COMPSOLID")
        return (int)TopAbs_COMPSOLID;
    else if (type == "TopAbs_SOLID")
        return (int)TopAbs_SOLID;
    else if (type == "TopAbs_SHELL")
        return (int)TopAbs_SHELL;
    else if (type == "TopAbs_FACE")
        return (int)TopAbs_FACE;
    else if (type == "TopAbs_WIRE")
        return (int)TopAbs_WIRE;
    else if (type == "TopAbs_EDGE")
        return (int)TopAbs_EDGE;
    else if (type == "TopAbs_VERTEX")
        return (int)TopAbs_VERTEX;
    else if (type == "TopAbs_SHAPE")
        return (int)TopAbs_SHAPE;
    else if (type == "UNKOWN")
        return -1;
}

std::string TopAbs2String(int type_)
{
    TopAbs_ShapeEnum type = (TopAbs_ShapeEnum)type_;
    switch (type)
    {
        case TopAbs_COMPOUND:
        {
            return "TopAbs_COMPOUND";
        }
        case TopAbs_COMPSOLID:
        {
            return "TopAbs_COMPSOLID";
        }
        case TopAbs_SOLID:
        {
            return "TopAbs_SOLID";
        }
        case TopAbs_SHELL:
        {
            return "TopAbs_SOLID";
        }
        case TopAbs_FACE:
        {
            return "TopAbs_FACE";
        }
        case TopAbs_WIRE:
        {
            return "TopAbs_WIRE";
        }
        case TopAbs_EDGE:
        {
            return "TopAbs_EDGE";
        }
        case TopAbs_VERTEX:
        {
            return "TopAbs_EDGE";
        }
        case TopAbs_SHAPE:
            return "TopAbs_SHAPE";
        default:
            return "UNKOWN";
    }
}