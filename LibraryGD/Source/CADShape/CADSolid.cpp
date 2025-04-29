#include "CADSolid.h"
#include "Library/CADShape/CADSolid.h"
#include <godot_cpp/core/class_db.hpp>

namespace godot
{
    void CADSolid::_bind_methods()
    {
        CADShape::_bind_methods();
    }

    CADSolid::CADSolid() {}
    CADSolid::~CADSolid() {}
}