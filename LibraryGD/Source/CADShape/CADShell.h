#pragma once

#include "CADShape.h"
#include <glm/glm.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <memory>
#include <string>

namespace Library
{
    class CADShell;
}

namespace godot
{
    class CADFace;

    class CADShell : public godot::CADShape
    {
        GDCLASS(CADShell, godot::CADShape)

      protected:
        static void _bind_methods();

      public:
        CADShell();
        virtual ~CADShell();

        const Library::CADShell& get() const;
        Library::CADShell&       get();

      private:
        TypedArray<godot::CADFace> getFaces() const;
    };
}