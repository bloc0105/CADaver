#include "HelloBottleGD.h"
#include <godot_cpp/core/class_db.hpp>
#include "Library/HelloBottle.h"

namespace godot
{
    void HelloBottleGD::_bind_methods()
    {
        ClassDB::bind_method(D_METHOD("exportBottle", "filename"), &HelloBottleGD::exportBottle);
    }

    HelloBottleGD::HelloBottleGD()
    {
        // Initialize any variables here.
    }

    HelloBottleGD::~HelloBottleGD()
    {
        // Add your cleanup here.
    }

    void exportBottle(const godot::String& filename_)
    {
        //std::string filename = filename_.utf8();
    }
}