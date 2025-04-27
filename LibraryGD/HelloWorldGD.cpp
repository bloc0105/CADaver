#include "HelloWorldGD.h"
#include <godot_cpp/core/class_db.hpp>
#include "Library/HelloWorld.h"

namespace godot
{
    void HelloWorldGD::_bind_methods()
    {
        ClassDB::bind_method(D_METHOD("getHelloWorldMessage"), &HelloWorldGD::helloWorldCall);
    }

    HelloWorldGD::HelloWorldGD()
    {
        // Initialize any variables here.
    }

    HelloWorldGD::~HelloWorldGD()
    {
        // Add your cleanup here.
    }

    godot::String HelloWorldGD::helloWorldCall()
    {
        return godot::String(HelloWorld().message().c_str());
    }
}