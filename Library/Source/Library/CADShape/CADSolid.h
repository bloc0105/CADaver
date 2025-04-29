#pragma once

#include "CADShape.h"

class TopoDS_Solid;

namespace Library
{
    class CADSolid : public CADShape
    {
      public:
        CADSolid();
        virtual ~CADSolid();

        virtual std::string toString() const override;
        virtual std::string getType() const override;

        TopoDS_Solid&       get();
        const TopoDS_Solid& get() const;

      private:
    };
}