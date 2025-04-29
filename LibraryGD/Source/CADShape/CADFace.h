#pragma once

#include "CADShape.h"
#include <glm/glm.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <memory>
#include <string>

namespace godot
{
    class CADFace : public godot::CADShape
    {
        GDCLASS(CADFace, godot::CADShape)

      protected:
        static void _bind_methods();

      public:
        CADFace();
        virtual ~CADFace();
    };
}