#include "CADShape.h"
#include "Library/CADShape.h"
#include <godot_cpp/core/class_db.hpp>

namespace godot
{
    void CADShape::_bind_methods()
    {
        ClassDB::bind_method(D_METHOD("loadCADFromFile", "filename"), &CADShape::loadFromFile);
        ClassDB::bind_method(D_METHOD("saveCADToFile", "filename"), &CADShape::saveToFile);
        ClassDB::bind_method(D_METHOD("getCADChildren"), &CADShape::getCadChildren);
    }

    CADShape::CADShape()
    {
        shape = std::make_unique<Library::CADShape>();
    }

    CADShape::~CADShape()
    {

    }

    bool CADShape::loadFromFile(const godot::String& str)
    {
        std::string filename = std::string(str.utf8());
        return shape->load(filename);
    }

    bool CADShape::saveToFile(const godot::String& str)
    {
        std::string filename = std::string(str.utf8());
        return shape->save(filename);
    }

    TypedArray<CADShape> CADShape::getCadChildren() const {
        TypedArray<CADShape> result;
        for (auto& x : shape->getChildren())
        {
            Ref<CADShape> sub;
            sub.instantiate();
            sub->shape = std::move(x);
            result.push_back(sub);
        }
        return result;
    }
    
    godot::String CADShape::_to_string() const
    {
        return shape->toString().c_str();
    }
}