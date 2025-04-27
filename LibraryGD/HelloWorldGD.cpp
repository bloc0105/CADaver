#include "HelloWorldGD.h"
#include <godot_cpp/core/class_db.hpp>
#include "Library/HelloWorld.h"

namespace godot
{
    void HelloWorldGD::_bind_methods()
    {
        ClassDB::bind_static_method("HelloWorldGD", D_METHOD("helloWorld"), &HelloWorldGD::call);    
    }

    HelloWorldGD::HelloWorldGD()
    {
        // Initialize any variables here.
    }

    HelloWorldGD::~HelloWorldGD()
    {
        // Add your cleanup here.
    }

    void HelloWorldGD::call()
    {
      HelloWorld().makeBottle();
    }
}