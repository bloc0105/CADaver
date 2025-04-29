#pragma once

#include <memory>
#include <string>
#include <vector>

#include "CADShape.h"

class TopoDS_CompSolid;

namespace Library
{
    class CADCompSolid : public CADShape
    {
      public:
        CADCompSolid();
        virtual ~CADCompSolid();

        virtual std::string toString() const override;
        virtual std::string getType() const override;

        TopoDS_CompSolid&       get();
        const TopoDS_CompSolid& get() const;

      private:
    };
}