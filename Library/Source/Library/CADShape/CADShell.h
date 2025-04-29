#pragma once

#include "CADShape.h"

class TopoDS_Shell;

namespace Library
{
    class CADShell : public CADShape
    {
      public:
        CADShell();
        virtual ~CADShell();

        virtual std::string toString() const override;
        virtual std::string getType() const override;

        TopoDS_Shell&       get();
        const TopoDS_Shell& get() const;
      private:
    };
}