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
        bool                 loadCadFromFile(const godot::String&);
        bool                 saveCadToFile(const godot::String&);
        TypedArray<CADShape> getCadChildren() const;
        godot::String        getCadType() const;

        std::unique_ptr<Library::CADShape> shape;
    };
}