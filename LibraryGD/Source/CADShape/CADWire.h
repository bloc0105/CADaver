#pragma once

#include "CADShape.h"
#include <glm/glm.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/variant/vector3.hpp>
#include <memory>
#include <string>

namespace Library
{
    class CADWire;
    class CADEdge;
}

namespace godot
{
    class CADEdge;

    class CADWire : public godot::CADShape
    {
        GDCLASS(CADWire, godot::CADShape)

      protected:
        static void _bind_methods();

      public:
        CADWire();
        virtual ~CADWire();

        const Library::CADWire& get() const;
        Library::CADWire&       get();
      private:
        TypedArray<godot::CADEdge> getEdges() const;
    };
}