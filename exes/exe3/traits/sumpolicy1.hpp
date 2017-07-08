// 15.1.4 Policies and Ploicy Classes

#ifndef SUMPOLICY_HPP
#define SUMPOLICY_HPP

class SumPolicy
{
public:
    template<typename T1, typename T2>
    static void accumulate(T1& total, T2 const & value)
    {
        total += value;
    }
};
#endif // SUMPOLICY_HPP
