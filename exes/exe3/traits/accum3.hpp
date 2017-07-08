// 15.1.2 Value Traits

#ifndef ACCUM_HPP
#define ACCUM_HPP

#include "accumtraits3.hpp"

template <typename T>
inline
typename AccumulationTraits<T>::AccT accum(T const* beg, T const* end)
{
    typedef typename AccumulationTraits<T>::AccT AccT;
    
    AccT total = AccumulationTraits<T>::zero;
    while (beg != end)
    {
        total += *beg;
        ++beg;
    }
    
    return total;
}

#endif // ACCUM_HPP
