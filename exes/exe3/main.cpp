#include <iostream>
//#include "traits/accum1.hpp"

#include "traits/accum8.hpp"

// 15.2 Type Functions
#include <stddef.h>

template<typename T>
class TypeSize
{
public:
    static size_t const value = sizeof(T);
    
};

// 15.1.4 Policies and Ploicy Classes
#include "traits/accum6.hpp"

template<typename T1, typename T2>
class MultPolicy
{
public:
    static void accumulate(T1& total, T2 const& value)
    {
        total *= value;
    }
};

// 15.2.2 Determining Class Types
#include "traits/isclasst.hpp"

class MyClass
{
};

struct MyStruct
{
};

union MyUnion
{
    
};

void myfunc()
{
}

enum E { e1 } e;

// check by passing type as template argument
template<typename T>
void check()
{
    if(IsClassT<T>::Yes)
    {
        std::cout   << " IsClassT " << std::endl;
    }
    else
    {
        std::cout   << " !IsClassT " << std::endl;
    }
}

// check by passing type as function call argument
template<typename T>
void checkT(T)
{
    check<T>();
}

// 15.2.1 Determining Element Types
#include <vector>
#include <list>
#include <stack>
#include <typeinfo>

template<typename T>
class ElementT;

template<typename T>
class ElementT<std::vector<T> >
{
public:
    typedef T Type;
};

template<typename T>
class ElementT<std::list<T> >
{
public:
    typedef T Type;
};

template<typename T>
class ElementT<std::stack<T> >
{
public:
    typedef T Type;
};

template<typename T>
void print_element_type(T const& c)
{
    std::cout   << "Container of "
    << typeid(typename ElementT<T>::Type).name()
    << " elements. \n";
}

// 15.2.3 Reference and Qualifiers
#include "traits/apply1.hpp"

void incr(int& a)
{
    ++a;
}

void print(int a)
{
    std::cout   << a << std::endl;
}

// 15.3.1 Read-only Parameter Types
#include "traits/rparam.hpp"
#include "traits/rparamcls.hpp"

// function that allows parameter passing by value or by reference
template<typename T1, typename T2>
void foo(typename RParam<T1>::Type p1, typename RParam<T2>::Type p2)
{
    std::cout   << "foo is activated " << std::endl;
}

// function that allows parameter passing by value or by reference
template<typename T1, typename T2>
void foo_core(typename RParam<T1>::Type p1, typename RParam<T2>::Type p2)
{
    std::cout   << "foo_core is activated " << std::endl;
}

// wrapper to avoid explicit template parameter passing
template<typename T1, typename T2>
inline
void foo(T1 const & p1, T2 const & p2)
{
    foo_core<T1,T2>(p1,p2);
}

int main(int argc, char *argv[])
{
    // 15.1.1 Fixed Traits
    int num[] = {1,2,3,4,5};
    
    std::cout   << "the average value of the integer values is "
                << Accum<int>::accum(&num[0], &num[5])/5
                << '\n';
    
    char name[] = "templates";
    int length = sizeof(name)-1;
    
    std::cout   << "the average value of the characters in \""
                << name << "\" is "
                << Accum<char>::accum(&name[0], &name[length]) / length
                << '\n';
    
    // 15.1.4 Policies and Ploicy Classes
    // #include "accum6.hpp"
    
    std::cout   << "the product of the integer values is "
                << Accum<int, MultPolicy>::accum(&num[0], &num[5])
                << '\n';
    
    // 15.2 Type Functions
    // traits/sizeof.cpp
    std::cout   << "TypeSize<int>::value = "
    << TypeSize<int>::value << std::endl;
   
    // 15.2.1 Determining Element Types
    // traits/elementtype.cpp
    std::stack<bool> s;
    print_element_type(s);
    
    // traits/isclasst.cpp
    std::cout   << "int: ";
    check<int>();
    
    std::cout   << "MyClass: ";
    check<MyClass>();
    
    std::cout   << "MyStruct: ";
    check<MyStruct>();
    
    std::cout   << "MyUnion: ";
    check<MyUnion>();
    
    std::cout   << "enum: ";
    checkT(e);
    
    std::cout   << "myfunc(): ";
    checkT(myfunc);
    
    int x = 7;
    apply(x, print);
    //apply(x, incr);
    
    // 15.3.1 Read-only Parameter Types
    MyClass1 mc1;
    MyClass2 mc2;
    foo<MyClass1, MyClass2>(mc1, mc2);
    
    return 0;
}
