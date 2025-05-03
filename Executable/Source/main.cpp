#include <iostream>

#include "Library/CADShape/CADFace.h"
#include "Library/CADShape/CADShape.h"
#include "Library/CADShape/CADShell.h"
#include "Library/CADShape/CADSolid.h"
#include "Library/CADShape/Triangulation.h"
#include "Library/Util/STLWriter.h"

std::vector<glm::dvec3> v;

void gather(const Library::CADShape& sub)
{
    auto typ = sub.getType();
    if (typ != "TopAbs_FACE")
    {
        for (const auto& subsub : sub.getChildren())
            gather(*subsub);
        return;
    }
    
    const Library::CADFace& face = (const Library::CADFace&)sub;

    auto triangulation = face.getTriangulation();

    if (triangulation)
    {
        for (size_t xx = 0; xx < triangulation->indices.size(); xx += 3)
        {
            v.push_back(triangulation->vertices[triangulation->indices[xx]]);
            v.push_back(triangulation->vertices[triangulation->indices[xx + 1]]);
            v.push_back(triangulation->vertices[triangulation->indices[xx + 2]]);
        }
    }
}

int main()
{
    auto shape = Library::CADShape::load("C:/Users/nicol/Downloads/Dagger1 v4.step");

    for (const auto& sub : shape->getChildren())
    {
        gather(*sub);
    }
    Library::STLWriter::write("C:/Users/nicol/Downloads/all.stl", v);
}