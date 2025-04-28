#include "CADShape.h"
#include "Library/CADShape.h"
#include <godot_cpp/core/class_db.hpp>

namespace godot
{
    void CADShape::_bind_methods()
    {
        ClassDB::bind_method(D_METHOD("loadFromFile", "filename"), &CADShape::loadFromFile);
        ClassDB::bind_method(D_METHOD("saveToFile", "filename"), &CADShape::saveToFile);
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
}