#pragma once

#include <string>
#include <memory>
#include "CADShape.h"

namespace godot
{
    class CADShapeFactory
    {
      public:
        static godot::Variant make(std::shared_ptr<Library::CADShape>);

    private:
    };
}