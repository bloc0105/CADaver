#pragma once

#include <string>
#include <memory>
#include <vector>

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
      std::string toString() const;

      std::vector<std::unique_ptr<CADShape>> getChildren() const;
    private:

      std::unique_ptr<TopoDS_Shape> data;
  };
}