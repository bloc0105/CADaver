#include "experiment.h"

#include <STEPControl_Reader.hxx>
#include <Transfer_Binder.hxx>
#include <TopExp_Explorer.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Solid.hxx>
#include <StepShape_ManifoldSolidBrep.hxx>
#include <TCollection_HAsciiString.hxx>
#include <iostream>
#include <XSControl_WorkSession.hxx>
#include <XSControl_TransferReader.hxx>

void experiment::main(const std::string& filename)
{
    STEPControl_Reader    reader;
    IFSelect_ReturnStatus status = reader.ReadFile(filename.c_str());
    if (status != IFSelect_RetDone)
    {
        std::cerr << "Error: cannot read STEP file " << filename << std::endl;
        return;
    }

    // Transfer the STEP roots. (Depending on your file, you may choose to call TransferRoots()
    // or iterate over each candidate root using TransferRoot(i).)
    Standard_Integer nRoots = reader.NbRootsForTransfer();
    for (Standard_Integer i = 1; i <= nRoots; i++)
    {
        reader.TransferRoot(i);
    }
    TopoDS_Shape mainShape = reader.OneShape();
    if (mainShape.IsNull())
    {
        std::cerr << "Error: no shape was transferred." << std::endl;
        return;
    }

    // Instead of accessing a Binder (which no longer exists), we use the transfer reader from the work session.
    Handle(XSControl_WorkSession) ws = reader.WS();
    // The TransferReader() available from the work session lets us map shapes back to their STEP entities.
    // In this example, for each solid we will call EntityFromShapeResult().

    std::cout << "Listing all TopoDS_Solid entities and their names from the STEP file:" << std::endl;

    // Explore all solids within the transferred shape.
    for (TopExp_Explorer exp(mainShape, TopAbs_SOLID); exp.More(); exp.Next())
    {
        TopoDS_Shape solid = exp.Current();

        // Retrieve the original STEP entity corresponding to 'solid'.
        // The second parameter (here, '1') is a mode flag that you may adjust per your needs.
        Handle(Standard_Transient) stepEntity = ws->TransferReader()->EntityFromShapeResult(solid, 1);

        if (!stepEntity.IsNull())
        {
            // Check that the STEP entity is a StepShape_ManifoldSolidBrep.
            if (stepEntity->IsKind(STANDARD_TYPE(StepShape_ManifoldSolidBrep)))
            {
                Handle(StepShape_ManifoldSolidBrep) brep  = Handle(StepShape_ManifoldSolidBrep)::DownCast(stepEntity);
                Handle(TCollection_HAsciiString) brepName = brep->Name();
                if (!brepName.IsNull())
                {
                    std::cout << "Solid Name: " << brepName->ToCString() << std::endl;
                }
                else
                {
                    std::cout << "Solid (from MANIFOLD_SOLID_BREP) has no specified name." << std::endl;
                }
            }
            else
            {
                std::cout << "The STEP entity for this solid is not a StepShape_ManifoldSolidBrep." << std::endl;
            }
        }
        else
        {
            std::cout << "No corresponding STEP entity found for this TopoDS_Solid." << std::endl;
        }
    }
}