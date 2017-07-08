tempalte<typename T1, typename T2>
class Promotion<Array<T1>, Array<T2> >
{
public:
    typedef Array<typename Promotion<T1, T2>::ResultT> ResultT;
};

templte<typename T>
class Promotion<Array<T>, Array<T> >
{
public:
    typedef Array<typename Promotion<T,T>::ResultT> ResultT;
}
