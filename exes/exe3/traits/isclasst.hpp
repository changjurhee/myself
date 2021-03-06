// 15.2.2 Determining Class Types

#ifndef ISCLASST_HPP
#define ISCLASST_HPP

template<typename T>
class IsClassT
{
private:
    typedef char One;
    typedef struct { char a[2]; } Two;
    template<typename C> static One test(int C::*);
    template<typename C> static Two test(...);
    
public:
    enum { Yes = sizeof(IsClassT<T>::test<T>(0)) == 1 };
    enum { No = !Yes };
};

#endif // ISCLASST_HPP
