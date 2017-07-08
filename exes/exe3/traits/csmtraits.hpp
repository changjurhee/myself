// 15.3.2 Copying, Swapping, and Moving

template<typename T>
class CSMtraits : public BitOrClassCSM<T, IsClassT<T>::No >
{
    
};
