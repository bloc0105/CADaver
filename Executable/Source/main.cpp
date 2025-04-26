#include <iostream>

#include "Library/HelloWorld.h"

int main()
{
    HelloWorld().makeBottle();

    std::cout << HelloWorld().message() << std::endl;
}