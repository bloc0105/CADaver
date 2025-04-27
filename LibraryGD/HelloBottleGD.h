#pragma once

#include <glm/glm.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <string>

namespace godot
{
    class HelloBottleGD : public Resource
    {
        GDCLASS(HelloBottleGD, Resource)

      protected:
        static void _bind_methods();

      public:
        HelloBottleGD();
        virtual ~HelloBottleGD();

        void exportBottle(const godot::String& filename); 
    };
}