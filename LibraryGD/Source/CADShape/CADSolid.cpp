#include "CADSolid.h"
#include "CADShell.h"
#include "Library/CADShape/CADShell.h"
#include "Library/CADShape/CADSolid.h"
#include <godot_cpp/core/class_db.hpp>

namespace godot
{
    void CADSolid::_bind_methods()
    {
        ClassDB::bind_method(D_METHOD("get_cad_shells"), &CADSolid::getShells);
    }

    CADSolid::CADSolid() {}
    CADSolid::~CADSolid() {}

    const Library::CADSolid& CADSolid::get() const
    {
        return (const Library::CADSolid&)getData();
    }

    Library::CADSolid& CADSolid::get()
    {
        return (Library::CADSolid&)getData();
    }

    TypedArray<godot::CADShell> CADSolid::getShells() const
    {
        TypedArray<godot::CADShell> result;
        for (auto& x : get().getShells())
        {
            Ref<godot::CADShell> sub;
            sub.instantiate();
            sub->setData(std::move(x));
            result.push_back(sub);
        }
        return result;
    }
}