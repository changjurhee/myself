#include <iostream>
#include "rparam.hpp"

class MyClass1
{
public:
    MyClass1()
    {
    }
    
    MyClass1(MyClass1 const&)
    {
        std::cout   << "MyCLass1 copy constructor called\n";
    }
};

class MyClass2
{
public:
    MyClass2() {}
    MyClass2(MyClass2 const&)
    {
        std::cout   << "MyClass2 copy constructor called\n";
    }
};

template<>
class RParam<MyClass2>
{
public:
    typedef MyClass2 Type;
};
