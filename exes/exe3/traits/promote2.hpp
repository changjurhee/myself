// 15.2.4 Promotion Traits

// partial specialization for two identical types
template<typename T>
class Promotion<T,T>
{
public:
    typedef T ResultT;
};
