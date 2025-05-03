#include "SaveFileDialog.h"

#include <nfd.h>
#include <string>
#include <iostream>
#include <stdexcept>


//int mainwubwubTestInclude(void)
//{
//
//    NFD_Init();
//
//    nfdu8char_t*      outPath;
//    nfdu8filteritem_t filters[2] = {
//        { "Source code", "c,cpp,cc" },
//        {     "Headers",    "h,hpp" }
//    };
//    nfdopendialogu8args_t args = { 0 };
//    args.filterList            = filters;
//    args.filterCount           = 2;
//    nfdresult_t result         = NFD_OpenDialogU8_With(&outPath, &args);
//    if (result == NFD_OKAY)
//    {
//        puts("Success!");
//        puts(outPath);
//        NFD_FreePathU8(outPath);
//    }
//    else if (result == NFD_CANCEL)
//    {
//        puts("User pressed cancel.");
//    }
//    else
//    {
//        printf("Error: %s\n", NFD_GetError());
//    }
//
//    NFD_Quit();
//    return 0;
//}


namespace Library
{
    SaveFileDialog::SaveFileDialog() {}
    SaveFileDialog::~SaveFileDialog() {}
}