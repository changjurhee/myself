#ifndef LIB1_H
#define LIB1_H

#include <head1.h>
#include <memory>
#include <iostream>

template<typename T>
class Less_than{
    const T val;
public:
    Less_than(const T& v) :val(v){}
    bool operator()(const T& x) const {return x < val;}
};

class lib1 : public head1
{
    typedef std::unique_ptr<int> uintptr;
    typedef std::shared_ptr<int> sintptr;
    
public:
    lib1();
    ~lib1();
    
    template<typename C, typename P>
    inline int Count(const C& c, P pred)
    {
        int Cnt = 0;
        for(const auto& x:c)
            if(pred(x))
                ++Cnt;
        
        return Cnt;
    }
    
    /*
     inline uintptr f(uintptr p)
    {
        ++*p;
        return p;
    }
    */
    
    inline void f2(const uintptr& p)
    {
        ++*p;
    }
    
    inline sintptr sf(sintptr p)
    {
        ++*p;
        return p;
    }
    
    inline void sf2(const sintptr& p)
    {
        ++*p;
    }
    
};

#endif
