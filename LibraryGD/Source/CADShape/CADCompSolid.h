#pragma once

#include "CADShape.h"
#include <glm/glm.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <memory>
#include <string>

namespace godot
{
    class CADCompSolid : public godot::CADShape
    {
        GDCLASS(CADCompSolid, godot::CADShape)

      protected:
        static void _bind_methods();

      public:
        CADCompSolid();
        virtual ~CADCompSolid();
    };
}