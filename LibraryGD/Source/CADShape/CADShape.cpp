#include "CADShape.h"
#include "Library/CADShape/CADShape.h"
#include <godot_cpp/core/class_db.hpp>
#include "CADShapeFactory.h"

namespace godot
{
    void CADShape::_bind_methods()
    {
        ClassDB::bind_method(D_METHOD("saveCADToFile", "filename"), &CADShape::saveCadToFile);
        ClassDB::bind_method(D_METHOD("getCADChildren"), &CADShape::getCadChildren);
        ClassDB::bind_method(D_METHOD("getCADType"), &CADShape::getCadType);

        ClassDB::bind_static_method("CADShape", D_METHOD("loadCADFromFile", "filename"), &CADShape::loadCadFromFile);
    }

    CADShape::CADShape()
    {
        shape = std::make_unique<Library::CADShape>();
    }

    CADShape::~CADShape() {}

    Ref<CADShape> CADShape::loadCadFromFile(const godot::String& str)
    {
        std::string filename = std::string(str.utf8());
        auto        result   = std::move(Library::CADShape::load(filename));
        if (result)
        {
            Ref<CADShape> resultGD = godot::CADShapeFactory::make(std::move(result));
            return resultGD;
        }
        return Ref<CADShape>();
    }

    bool CADShape::saveCadToFile(const godot::String& str)
    {
        std::string filename = std::string(str.utf8());
        return shape->save(filename);
    }

    TypedArray<CADShape> CADShape::getCadChildren() const
    {
        TypedArray<CADShape> result;
        for (auto& x : shape->getChildren())
        {
            Ref<CADShape> sub;
            sub.instantiate();
            sub->shape = std::move(x);
            result.push_back(sub);
        }
        return result;
    }

    godot::String CADShape::_to_string() const
    {
        return shape->toString().c_str();
    }

    godot::String CADShape::getCadType() const
    {
        return shape->getType().c_str();
    }

    void CADShape::setData(std::unique_ptr<Library::CADShape> data)
    {
        shape = std::move(data);
    }
}