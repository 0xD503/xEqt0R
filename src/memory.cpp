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


/// Explicit template instantiation. It is done in order to keep template
/// implementation separately from its declaration
//template class Memory<size_t>;
template class Memory<word>;
//template class Memory<i_mem_addr_t>;
//template class Memory<d_mem_addr_t>;
