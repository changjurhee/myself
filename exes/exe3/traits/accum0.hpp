// 15.1.8 Accumulation with general iterators

#ifndef ACCUM_HPP
#define ACCUM_HPP

#include <iterator>

template <typename Iter>
inline
typename std::iterator_traits<Iter>::value_type
accum(Iter start, Iter end)
{
    typedef typename std::iterator_traits<Iter>::value_type VT;
    VT total = VT();
    while(start != end)
    {
        total += *start;
        ++start;
    }
    
    return total;
}

#endif // ACCUM_HPP
