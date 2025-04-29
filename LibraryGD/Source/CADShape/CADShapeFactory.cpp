#include "CADShapeFactory.h"

#include "CADCompSolid.h"
#include "CADCompound.h"
#include "CADEdge.h"
#include "CADFace.h"
#include "CADShell.h"
#include "CADSolid.h"
#include "CADVertex.h"
#include "CADWire.h"
#include "Library/CADShape/CADCompSolid.h"
#include "Library/CADShape/CADCompound.h"
#include "Library/CADShape/CADEdge.h"
#include "Library/CADShape/CADFace.h"
#include "Library/CADShape/CADShell.h"
#include "Library/CADShape/CADSolid.h"
#include "Library/CADShape/CADVertex.h"
#include "Library/CADShape/CADWire.h"

namespace godot
{
    godot::Ref<godot::CADShape> CADShapeFactory::make(std::unique_ptr<Library::CADShape> data)
    {
        godot::Ref<godot::CADShape> result;

        auto type = data->getType();

        if (type == "TopAbs_COMPOUND")
            result = godot::Ref<godot::CADCompound>();
        else if (type == "TopAbs_COMPSOLID")
            result = godot::Ref<godot::CADCompSolid>();
        else if (type == "TopAbs_SOLID")
            result = godot::Ref<godot::CADSolid>();
        else if (type == "TopAbs_SHELL")
            result = godot::Ref<godot::CADShell>();
        else if (type == "TopAbs_FACE")
            result = godot::Ref<godot::CADShell>();
        else if (type == "TopAbs_WIRE")
            result = godot::Ref<godot::CADWire>();
        else if (type == "TopAbs_EDGE")
            result = godot::Ref<godot::CADEdge>();
        else if (type == "TopAbs_VERTEX")
            result = godot::Ref<godot::CADVertex>();
        else if (type == "TopAbs_SHAPE")
            result = godot::Ref<godot::CADShape>();
        result.instantiate();
        result->setData(std::move(data));
        return result;
    }
}