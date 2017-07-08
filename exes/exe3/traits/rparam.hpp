// 15.3.1 Read-only Parameter Types

#ifndef RPARAM_HPP
#define RPARAM_HPP

#include "ifthenelse.hpp"
#include "isclasst.hpp"

template<typename T>
class RParam
{
public:
    typedef typename IfThenElse<IsClassT<T>::No,
                                T,
                                T const&>::ResultT Type;
};

#endif // RPARAM_HPP
