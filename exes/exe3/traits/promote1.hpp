// 15.2.4 Promotion Traits

// primary template for type promotion
template<typename T1, typename T2>
class Promotion
{
public:
    typedef typename
    IfThenElse<(sizeof(T1)>sizeof(T2)),
                T1,
                typename IfThenElse<(sizeof(T1)<sizeof(T2)),
                                    T2,
                                    void
                                    >::ResultT
                >::ResultT ResultT;
};
