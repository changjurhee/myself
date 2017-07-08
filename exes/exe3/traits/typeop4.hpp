// 15.2.3 Reference and Qualifiers

template<>
class TypeOp<void>  // full specialization for void
{
public:
    typedef void        ArgT;
    typedef void        BareT;
    typedef void const  ConstT;
    typedef void        RefT;
    typedef void        RefBareT;
    typedef void        RefConstT;
};
