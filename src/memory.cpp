#include "memory.hpp"
#include <cstddef>


template<typename T>
Memory<T>::Memory(size_t len) :
    _length(len), _size(_length * sizeof(T)),
    _memory(_length)
{
    //
}

template<typename T>
Memory<T>::~Memory(void)
{
    //
}
