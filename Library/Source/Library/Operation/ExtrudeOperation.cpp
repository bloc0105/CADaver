#include "ExtrudeOperation.h"

#include "CADShape/CADShapeFactory.h"
#include "CADShape/CADShape.h"

#include <BRepPrimAPI_MakePrism.hxx>
#include <BRep_Builder.hxx>

namespace Library
{
    std::unique_ptr<CADShape> ExtrudeOperation::extrude(const CADShape& input, const glm::dvec3& direction)
    {
        BRepPrimAPI_MakePrism prismMaker(input.getData(), gp_Vec(direction.x, direction.y, direction.z));
        TopoDS_Shape          extrudedShape = prismMaker.Shape();
        if (!extrudedShape.IsNull())
            return nullptr;

        return CADShapeFactory::make(extrudedShape);
    }
}