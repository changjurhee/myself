#include "dll1.h"
#include "../../libssrc/lib1/lib1.h"
#include <iostream>
#include <thread>

dll1::dll1(){}
dll1::~dll1(){}

void hello()
{
    std::cout << "Hello Concurrent World\n";
}

const char* dll1::getText()
{
    lib1 iLib1;
    
    //std::unique_ptr<int> p{new int{7}};
    
    //p = iLib1.f(std::move(p));
    
    //iLib1.f2(p);
    
    //Less_than<int> lti{42};
    //Less_than<std::string> lts{"bask"};
    
    //bool b1 = lti(4);
    //bool b2 = lts("555");
    
    std::thread t(hello);
    t.join();
    
    return iLib1.getText();
    
    //return "ggg";
}
