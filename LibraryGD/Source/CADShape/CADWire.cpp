#include "CADWire.h"
#include "Library/CADShape/CADWire.h"
#include <godot_cpp/core/class_db.hpp>

namespace godot
{
    void CADWire::_bind_methods()
    {
        CADShape::_bind_methods();
    }

    CADWire::CADWire() {}
    CADWire::~CADWire() {}
}