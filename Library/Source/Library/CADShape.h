#pragma once

#include <string>
#include <memory>

class TopoDS_Shape;

namespace Library
{
  class CADShape
  {
    public:
      CADShape();
      ~CADShape();

      bool save(const std::string& filename) const;
      bool load(const std::string& filename);
    private:

      std::unique_ptr<TopoDS_Shape> data;
  };
}