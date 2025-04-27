#pragma once

class TopoDS_Shape;

class BoxTriangulator
{
  public:
    BoxTriangulator();

    static void triangulate(const TopoDS_Shape& boxShape);

  private:
};