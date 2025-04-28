#pragma once

#include <glm/glm.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <memory>
#include <string>

namespace Library
{
    class CADShape;
}

namespace godot
{
    class CADShape : public RefCounted
    {
        GDCLASS(CADShape, RefCounted)

      protected:
        static void _bind_methods();

      public:
        CADShape();
        virtual ~CADShape();

        godot::String _to_string() const;

      private:
        bool                 loadFromFile(const godot::String&);
        bool                 saveToFile(const godot::String&);
        TypedArray<CADShape> getCadChildren() const;

        std::unique_ptr<Library::CADShape> shape;
    };
}