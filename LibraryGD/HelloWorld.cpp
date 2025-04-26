#include "HelloWorld.h"
#include <godot_cpp/core/class_db.hpp>

namespace godot
{
    void HelloWorld::_bind_methods()
    {
        ClassDB::bind_method(D_METHOD("get_position"), &HelloWorld::get_position);
        ClassDB::bind_method(D_METHOD("set_position", "val"), &HelloWorld::set_position);
        ClassDB::bind_method(D_METHOD("get_category"), &HelloWorld::get_category);
        ClassDB::bind_method(D_METHOD("set_category", "val"), &HelloWorld::set_category);
        ClassDB::bind_method(D_METHOD("get_size"), &HelloWorld::get_size);
        ClassDB::bind_method(D_METHOD("set_size", "val"), &HelloWorld::set_size);

        ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "position"), "set_position", "get_position");
        ADD_PROPERTY(PropertyInfo(Variant::INT, "category"), "set_category", "get_category");
        ADD_PROPERTY(PropertyInfo(Variant::INT, "size"), "set_size", "get_size");
    }

    HelloWorld::HelloWorld()
    {
        // Initialize any variables here.
    }

    HelloWorld::~HelloWorld()
    {
        // Add your cleanup here.
    }

    Vector2 HelloWorld::get_position() const
    {
        return Vector2(position.x, position.y);
    }
    void HelloWorld::set_position(const Vector2& v)
    {
        position = glm::dvec2(v.x, v.y);
    }
    int HelloWorld::get_category() const
    {
        return category;
    }
    void HelloWorld::set_category(int c)
    {
        category = c;
    }
    int HelloWorld::get_size() const
    {
        return size;
    }
    void HelloWorld::set_size(int v)
    {
        size = v;
    }
}