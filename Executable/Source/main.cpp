#include <iostream>

#include "Library/Util/SaveFileDialog.h"
#include "Library/Util/LoadFileDialog.h"
#include "Library/Operation/TriangulateOperation.h"
#include "Library/Util/Triangulation.h"
#include "Library/CADShape/CADShape.h"


int main()
{
    Library::LoadFileDialog dlg;
    dlg.addFilter("step files", { "STP", "STEP" });
    dlg.execute();
    std::cout << "Cancel: " << dlg.isCancled() << std::endl; 

    if (!dlg.isCancled())
    {
        auto shape = Library::CADShape::load(dlg.getResultPath());
        auto tri = Library::TriangulateOperation::triangulate(*shape);
        tri->saveAsSTL(dlg.getResultPath() + ".stl");
    }
    std::cout << dlg.getResultPath();
}