// 15.2.4 Promotion Traits

#ifndef IFTHENELSE_HPP
#define IFTHENELSE_HPP

// primary template: yield second or third argument depending on first argument
template<bool C, typename Ta, typename Tb>
class IfThenElse;

// partial specialization: true yields second atgument
template<typename Ta, typename Tb>
class IfThenElse<true, Ta, Tb>
{
public:
    typedef Ta ResultT;
};

// partial specialization: false yields third argument
template<typename Ta, typename Tb>
class IfThenElse<false, Ta, Tb>
{
public:
    typedef Tb ResultT;
};

#endif // IFTHENELSE_HPP


