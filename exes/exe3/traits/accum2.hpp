// 15.1.1 Fixed Traits

#ifndef ACCUM_HPP
#define ACCUM_HPP

#include "accumtraits2.hpp"

template <typename T>
inline
typename AccumulationTraits<T>::AccT accum(T const* beg, T const* end)
{
    typedef typename AccumulationTraits<T>::AccT AccT;
    
    AccT total = AccT();
    while (beg != end)
    {
        total += *beg;
        ++beg;
    }
    
    return total;
}

#endif // ACCUM_HPP
