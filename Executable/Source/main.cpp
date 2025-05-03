#include <iostream>

#include "Library/Util/SaveFileDialog.h"
#include "Library/Util/LoadFileDialog.h"


int main()
{
    Library::LoadFileDialog dlg;
    dlg.addFilter("step files", { "STP", "STEP" });
    dlg.execute();
    std::cout << "Cancel: " << dlg.isCancled() << std::endl; 
    std::cout << dlg.getResultPath();
}