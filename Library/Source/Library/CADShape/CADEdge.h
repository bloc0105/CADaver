#pragma once

#include "CADShape.h"

class TopoDS_Edge;

namespace Library
{
    class CADEdge : public CADShape
    {
      public:
        CADEdge();
        virtual ~CADEdge();

        virtual std::string toString() const override;
        virtual std::string getType() const override;

        TopoDS_Edge&       get();
        const TopoDS_Edge& get() const;

      private:
    };
}