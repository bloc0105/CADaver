#include "CADFace.h"

#include "CADWire.h"
#include "TopAbs2String.h"
#include "Triangulation.h"

#include <BRepGProp.hxx>
#include <BRepMesh_IncrementalMesh.hxx>
#include <BRepTools_ShapeSet.hxx>
#include <BRep_Tool.hxx>
#include <GProp_GProps.hxx>
#include <Poly_Triangle.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopExp_Explorer.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Face.hxx>

namespace Library
{
    CADFace::CADFace() {}
    CADFace::~CADFace() {}

    std::string CADFace::toString() const
    {
        std::stringstream ss;
        GProp_GProps      props;
        BRepGProp::SurfaceProperties(TopoDS::Face(getData()), props);
        ss << "Face, A=" << std::fixed << std::setprecision(2) << props.Mass();
        bool isClosed = BRep_Tool::IsClosed(TopoDS::Face(getData()));
        if (isClosed)
            ss << ", C";
        std::string result = ss.str();
        return result;
    }

    std::string CADFace::getType() const
    {
        return TopAbs2String(TopAbs_FACE);
    }

    TopoDS_Face& CADFace::get()
    {
        return (TopoDS_Face&)getData();
    }

    const TopoDS_Face& CADFace::get() const
    {
        return (const TopoDS_Face&)getData();
    }

    std::vector<std::unique_ptr<CADWire>> CADFace::getWires() const
    {
        std::vector<std::unique_ptr<CADWire>> result;
        TopExp_Explorer                       wireExplorer(get(), TopAbs_WIRE);
        while (wireExplorer.More())
        {
            TopoDS_Wire wire = TopoDS::Wire(wireExplorer.Current());
            auto        sub  = std::make_unique<CADWire>();
            sub->setData(wire);
            result.push_back(std::move(sub));
            wireExplorer.Next();
        }
        return result;
    }

    std::string CADFace::getOrientation() const
    {
        return TopAbsOrientation2String(get().Orientation());
    }

    std::unique_ptr<Triangulation> CADFace::getTriangulation(double precision) const
    {
        std::unique_ptr<Triangulation> result = std::make_unique<Triangulation>();

        TopAbs_Orientation o = get().Orientation();
        bool               reversed = o == 1;


        BRepMesh_IncrementalMesh mesher(getData(), precision);
        mesher.Perform();
        TopLoc_Location loc;
        Handle(Poly_Triangulation) triangulation = BRep_Tool::Triangulation(get(), loc);

        if (triangulation.IsNull())
            return {};

        size_t triangleAmount = triangulation->NbTriangles();
        size_t verticesAmount = triangulation->NbNodes();
        result->indices.reserve(triangleAmount * 3);
        result->vertices.reserve(verticesAmount);

        for (size_t i = 0; i < triangleAmount; i++)
        {
            const Poly_Triangle& tri = triangulation->Triangle(i + 1);
            int                  a, b, c;
            tri.Get(a, b, c);
            if (reversed)
            {
                result->indices.push_back(a - 1);
                result->indices.push_back(c - 1);
                result->indices.push_back(b - 1);
            }
            else
            {
                result->indices.push_back(a - 1);
                result->indices.push_back(b - 1);
                result->indices.push_back(c - 1);
            }
        }

        for (size_t i = 0; i < verticesAmount; i++)
        {
            auto node = triangulation->Node(i + 1);
            result->vertices.push_back(glm::dvec3(node.X(), node.Y(), node.Z()));
        }

        return std::move(result);
    }
}