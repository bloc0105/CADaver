#pragma once

#include "CADShape.h"

class TopoDS_Wire;

namespace Library
{
    class CADWire : public CADShape
    {
      public:
        CADWire();
        virtual ~CADWire();

        virtual std::string toString() const override;
        virtual std::string getType() const override;

        TopoDS_Wire&       get();
        const TopoDS_Wire& get() const;

      private:
    };
}