#pragma once

#include "CADShape.h"
#include <glm/glm.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <memory>
#include <string>

namespace Library
{
    class CADFace;
    class CADWire;
}


namespace godot
{
    class CADWire;

    class CADFace : public godot::CADShape
    {
        GDCLASS(CADFace, godot::CADShape)

      protected:
        static void _bind_methods();

      public:
        CADFace();
        virtual ~CADFace();

        const Library::CADFace& get() const;
        Library::CADFace&       get();
      private:
        TypedArray<godot::CADWire> getWires() const;
    };
}