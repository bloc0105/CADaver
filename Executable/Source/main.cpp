#include <iostream>

#include "Library/HelloBottle.h"
#include "Library/BoxTriangulate.h"
#include "Library/IterateShapes.h"

int main()
{
    HelloBottle bottle;
    bottle.makeBottle();
    ////bottle.exportBottle("bottle.stp");

    std::cin.get();
    bottle.investigateBottle();

    //IterateShapes();
}