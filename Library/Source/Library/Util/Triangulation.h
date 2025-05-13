#pragma once

#include <glm/glm.hpp>
#include <vector>

namespace Library
{
    class Triangulation
    {
      public:
        Triangulation();
        virtual ~Triangulation();

        std::vector<glm::dvec3> vertices;
        std::vector<int>        indices;
    };
}