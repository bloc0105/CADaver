#pragma once

#include <string>
#include <memory>
#include "CADShape.h"

namespace godot
{
    class CADShapeFactory
    {
      public:
        static Ref<godot::CADShape> make(std::unique_ptr<Library::CADShape>);

    private:
    };
}