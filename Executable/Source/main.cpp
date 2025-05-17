#include <iostream>

#include "Library/Util/SaveFileDialog.h"
#include "Library/Util/LoadFileDialog.h"
#include "Library/Operation/TriangulateOperation.h"
#include "Library/Util/Triangulation.h"
#include "Library/CADShape/CADShape.h"
#include "Library/CADShape/CADShapeFactory.h"

#include "Library/experiment.h"

int main()
{
    Library::LoadFileDialog dlg;
    dlg.addFilter("step files", { "STP", "STEP" });
    dlg.execute();
    std::cout << "Cancel: " << dlg.isCancled() << std::endl; 

    if (!dlg.isCancled())
    {
        experiment().main(dlg.getResultPath());
    }
    std::cout << dlg.getResultPath();
}