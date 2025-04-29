#pragma once

#include "CADShape.h"
#include <glm/glm.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <memory>
#include <string>

namespace godot
{
    class CADShell : public godot::CADShape
    {
        GDCLASS(CADShell, godot::CADShape)

      protected:
        static void _bind_methods();

      public:
        CADShell();
        virtual ~CADShell();
    };
}