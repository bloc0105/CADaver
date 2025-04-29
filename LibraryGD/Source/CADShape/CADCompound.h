#pragma once

#include <glm/glm.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <memory>
#include <string>
#include "CADShape.h"

namespace godot
{
    class CADCompound : public godot::CADShape
    {
        GDCLASS(CADCompound, godot::CADShape)

      protected:
        static void _bind_methods();

      public:
        CADCompound();
        virtual ~CADCompound();
    };
}