#include <iostream>
#include "traits/accum1.hpp"

int main(int argc, char *argv[])
{
    int num[] = {1,2,3,4,5};
    
    std::cout   << "the average value of the integer values is "
                << accum(&num[0], &num[5])/5
                << '\n';
    
    char name[] = "templates";
    int length = sizeof(name)-1;
    
    std::cout   << "the average value of the characters in \""
                << name << "\" is "
                << accum(&name[0], &name[length]) / length
                << '\n';
   
    return 0;
}
