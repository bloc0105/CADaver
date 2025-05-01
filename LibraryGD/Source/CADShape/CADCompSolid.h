#pragma once

#include "CADShape.h"
#include <glm/glm.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <memory>
#include <string>

namespace Library
{
    class CADCompSolid;
}

namespace godot
{
    class CADSolid;

    class CADCompSolid : public godot::CADShape
    {
        GDCLASS(CADCompSolid, godot::CADShape)

      protected:
        static void _bind_methods();

      public:
        CADCompSolid();
        virtual ~CADCompSolid();

        const Library::CADCompSolid& get() const;
        Library::CADCompSolid&       get();

      private:
        TypedArray<godot::CADSolid> getSolids() const;
    };
}