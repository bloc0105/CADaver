#pragma once

#include <string>
#include <memory>

class TopoDS_Shape;

namespace Library
{
    class CADShape;

    class CADShapeFactory
    {
      public:
        static std::unique_ptr<CADShape> make(const std::string& filename);
        static std::unique_ptr<CADShape> make(int type);
        static std::unique_ptr<CADShape> make(std::unique_ptr<TopoDS_Shape>);

    private:
    };
}