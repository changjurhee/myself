// 15.3.2 Copying, Swapping, and Moving

#include <cstring>
#include <cassert>
#include <stddef.h>
#include "csm1.hpp"

// partial specialization for fast bitwise copying of objects
template<typename T>
class BitOrClassCSM<T, true> : public BitOrClassCSM<T, false>
{
public:
    static void copy_n(T const* src, T* dst, size_t n)
    {
        // copy n items onto n other ones
        std::memcpy((void*)dst, (void*)src, n*sizeof(T));
    }
    
    static void copy_init_n(T const* src, void* dst, size_t n)
    {
        // copy n items onto unintialized storgae
        std::memcpy(dst, (void*)src, n*sizeof(T));
    }
    
    static void move_n(T* src, T* dst, size_t n)
    {
        // move n items onto other ones
        assert(src != dst);
        std::memcpy((void*)dst, (void*)src, n*sizeof(T));
    }
    
    static void move_init_n(T const* src, void* dst, size_t n)
    {
        // move n items onto unintialized storage
        assert(src != dst);
        std::memcpy(dst, (void*)src, n*sizeof(T));
    }
}
