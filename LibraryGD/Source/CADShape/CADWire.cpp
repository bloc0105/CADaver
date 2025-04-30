#include "CADWire.h"

#include "CADEdge.h"
#include "Library/CADShape/CADWire.h"
#include "Library/CADShape/CADEdge.h"
#include <godot_cpp/core/class_db.hpp>

namespace godot
{
    void CADWire::_bind_methods()
    {
        ClassDB::bind_method(D_METHOD("get_cad_edges"), &CADWire::getEdges);
    }

    CADWire::CADWire() {}
    CADWire::~CADWire() {}

    const Library::CADWire& CADWire::get() const
    {
        return (const Library::CADWire&)getData();
    }
    Library::CADWire& CADWire::get()
    {
        return (Library::CADWire&)getData();
    }

    TypedArray<godot::CADEdge> CADWire::getEdges() const
    {
        TypedArray<godot::CADEdge> result;
        for (auto& x : get().getEdges())
        {
            Ref<godot::CADEdge> sub;
            sub.instantiate();
            sub->setData(std::move(x));
            result.push_back(sub);
        }
        return result;
    }
}