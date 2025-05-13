#include "Triangulation.h"

#include "STLWriter.h"

namespace Library
{
    Triangulation::Triangulation() {}
    Triangulation::~Triangulation() {}

    void Triangulation::saveAsSTL(const std::string& filename) const
    {
        std::vector<glm::dvec3> tri;
        tri.resize(indices.size());
        for (size_t i = 0; i < indices.size(); i++)
            tri[i] = vertices[indices[i]];

        STLWriter::write(filename, tri);
    }
}