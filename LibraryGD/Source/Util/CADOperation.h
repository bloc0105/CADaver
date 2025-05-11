#pragma once

#include <godot_cpp/classes/node3d.hpp>
#include <memory>
#include "CADShape/CADShape.h"

namespace godot
{
    class CADShape;

    class CADOperation : public RefCounted
    {
        GDCLASS(CADOperation, RefCounted)

      protected:
        static void _bind_methods();

      public:
        CADOperation();
        virtual ~CADOperation();

      private:
        static Ref<godot::CADShape> extrude(Ref<godot::CADShape>, Vector3 direction);


    };
}