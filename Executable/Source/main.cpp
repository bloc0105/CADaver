#include <iostream>

#include "Library/Experiments/HelloBottle.h"
#include "Library/Experiments/BoxTriangulate.h"
#include "Library/Experiments/IterateShapes.h"

int main()
{
    HelloBottle bottle;
    bottle.makeBottle();
    ////bottle.exportBottle("bottle.stp");

    //std::cin.get();
    bottle.investigateBottle();

    //IterateShapes();
}