// 15.2.3 Reference and Qualifiers

template<typename T>
void apply(T& arg, void (*func)(T))
{
    func(arg);
}

/*
template<typename T>
void apply(typename TypeOp<T>::RefT arg, void (*func)(T))
{
    func(arg);
}
*/
