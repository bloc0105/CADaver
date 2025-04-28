#pragma once

#include <glm/glm.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <string>
#include <memory>

namespace Library
{
    class CADShape;
}

namespace godot
{
    class CADShape : public Node3D
    {
        GDCLASS(CADShape, Node3D)

      protected:
        static void _bind_methods();

      public:
        CADShape();
        virtual ~CADShape();

      private:
        bool loadFromFile(const godot::String&);
        bool saveToFile(const godot::String&);

        std::unique_ptr<Library::CADShape> shape;
    };
}