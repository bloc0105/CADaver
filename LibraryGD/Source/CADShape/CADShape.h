#pragma once

#include <glm/glm.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/array_mesh.hpp>
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

        void setData(std::unique_ptr<Library::CADShape>);

        Library::CADShape&       getData();
        const Library::CADShape& getData() const;

      private:
        static Ref<CADShape> loadCadFromFile(const godot::String&);
        bool                 saveCadToFile(const godot::String&);
        Array                getCadChildren() const;
        godot::AABB          getAABB() const;
        godot::String        getCadType() const;
        Ref<ArrayMesh>       getTriangulation(double precision = 0.1) const;

        std::unique_ptr<Library::CADShape> shape;
    };
}