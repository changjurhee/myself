// 15.2.3 Reference and Qualifiers

template<typename T>
class TypeOp<T&>
{
public:
    typedef T   &                       ArgT;
    typedef typename TypeOp<T>::BareT   BareT;
    typedef T const                     ConstT;
    typedef T   &                       RefT;
    typedef typename TypeOp<T>::BareT   RefBareT;
    typedef T const &                   RefconstT;
}
