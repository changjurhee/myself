// 15.1.1 Fixed Traits

template<typename T>
class AccumulationTraits;

template<>
class AccumulationTraits<char>
{
public:
    typedef int AccT;
};

template<>
class AccumulationTraits<short>
{
public:
    typedef int AccT;
};

template<>
class AccumulationTraits<int>
{
public:
    typedef long AccT;
};

template<>
class AccumulationTraits<unsigned int>
{
public:
    typedef unsigned long AccT;
};

template<>
class AccumulationTraits<float>
{
public:
    typedef double AccT;
};
