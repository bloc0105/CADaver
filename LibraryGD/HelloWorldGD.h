#pragma once

#include <glm/glm.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <string>

namespace godot
{
    class HelloWorldGD : public Resource
    {
        GDCLASS(HelloWorldGD, Resource)

      protected:
        static void _bind_methods();

      public:
        HelloWorldGD();
        virtual ~HelloWorldGD();

        godot::String helloWorldCall(); 
    };
}