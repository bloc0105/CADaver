#include "CADFace.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/surface_tool.hpp>

#include "Library/CADShape/CADFace.h"
#include "Library/CADShape/CADWire.h"
#include "Library/CADShape/Triangulation.h"

#include "CADWire.h"

namespace godot
{
    void CADFace::_bind_methods()
    {
        ClassDB::bind_method(D_METHOD("get_cad_wires"), &CADFace::getWires);
        ClassDB::bind_method(D_METHOD("get_cad_triangulation"), &CADFace::getTriangulation);
    }

    CADFace::CADFace() {}
    CADFace::~CADFace() {}

    const Library::CADFace& CADFace::get() const
    {
        return (const Library::CADFace&)getData();
    }

    Library::CADFace& CADFace::get()
    {
        return (Library::CADFace&)getData();
    }

    TypedArray<godot::CADWire> CADFace::getWires() const
    {
        TypedArray<godot::CADWire> result;
        for (auto& x : get().getWires())
        {
            Ref<godot::CADWire> sub;
            sub.instantiate();
            sub->setData(std::move(x));
            result.push_back(sub);
        }
        return result;
    }

    Ref<ArrayMesh> CADFace::getTriangulation() const
    {
        auto mesh = get().getTriangulation();
        if (!mesh)
            return nullptr;

        Ref<SurfaceTool> st;
        st.instantiate();
        st->begin(Mesh::PRIMITIVE_TRIANGLES);

        for (size_t i = 0; i < mesh->vertices.size(); ++i)
        {
            auto v = Vector3((real_t)mesh->vertices[i].x, (real_t)mesh->vertices[i].y, (real_t)mesh->vertices[i].z);
            st->add_vertex(v);
        }
        PackedInt32Array godot_indices;
        godot_indices.resize(mesh->indices.size());
        for (size_t i = 0; i < mesh->indices.size(); ++i)
        {
            st->add_index(mesh->indices[i]);
        }
        Ref<ArrayMesh> result = st->commit();
        return result;
    }
}