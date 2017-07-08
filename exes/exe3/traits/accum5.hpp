// 15.1.3 Parameterized Traits

#ifndef ACCUM_HPP
#define ACCUM_HPP

#include "accumtraits4.hpp"

template <typename T,
          typename AT = AccumulationTraits<T> >
class Accum
{
public:
    static typename AT::AccT accum(T const* beg, T const* end)
    {
        typename AT::AccT total = AT::zero();
        while(beg != end)
        {
            total += *beg;
            ++beg;
        }
        return total;
    }
};
#endif // ACCUM_HPP
