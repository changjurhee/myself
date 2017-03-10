#include "../../dlls/dll1/dll1.h"
#include <iostream>

int main(int argc, char *argv[])
{
    dll1 iDll1;
    std::cout << iDll1.getText() << std::endl;
    
    return 0;
}
