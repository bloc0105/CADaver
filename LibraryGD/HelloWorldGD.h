#pragma once

#include <glm/glm.hpp>
#include <godot_cpp/classes/resource.hpp>

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

        void call();
    };
}