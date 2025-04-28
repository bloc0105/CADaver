#include "CADShape.h"

#include <BRep_Builder.hxx>
#include <STEPControl_Reader.hxx>
#include <STEPControl_Writer.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Compound.hxx>

namespace Library
{

    CADShape::CADShape()
    {
        data = std::make_unique<TopoDS_Compound>();
    }

    CADShape::~CADShape() {}

    bool CADShape::save(const std::string& filename) const
    {
        // https://dev.opencascade.org/content/export-multi-shapes-single-step-file
        //  Write resulting compound to the file.
        STEPControl_Writer    aWriter;
        IFSelect_ReturnStatus aStat = aWriter.Transfer(*data, STEPControl_AsIs);
        aStat                       = aWriter.Write("bottle.stp");
        if (aStat != IFSelect_RetDone)
            return false;
        return true;
    }

    bool CADShape::load(const std::string& filename)
    {
        STEPControl_Reader    reader;
        IFSelect_ReturnStatus status = reader.ReadFile(filename.c_str());

        if (status != IFSelect_RetDone)
            return false;
        reader.TransferRoots();
        *data = reader.OneShape();
        return true;
    }
}