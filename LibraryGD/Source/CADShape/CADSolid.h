#pragma once

#include "CADShape.h"
#include <glm/glm.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <memory>
#include <string>

namespace Library
{
    class CADSolid;
}

namespace godot
{
    class CADShell;

    class CADSolid : public godot::CADShape
    {
        GDCLASS(CADSolid, godot::CADShape)

      protected:
        static void _bind_methods();

      public:
        CADSolid();
        virtual ~CADSolid();

        const Library::CADSolid& get() const;
        Library::CADSolid&       get();

      private:
        TypedArray<godot::CADShell> getShells() const;

        godot::String getName() const;
        void          setName(godot::String);       

    };
}