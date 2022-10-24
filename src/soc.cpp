#include "soc.hpp"


template<typename T, typename M>
SoC<T, M>::SoC(size_t len) :
    _cpu(), _memory(len)
{
    //
}

template<typename T, typename M>
SoC<T, M>::~SoC(void)
{
    //
}


template<typename T, typename M>
void SoC<T, M>::run (void)
{
    //
}


/// Explicit template instantiation. It is done in order to keep template
/// implementation separately from its declaration
template class SoC<archBitDepth, i_mem_addr_t>;
template class SoC<archBitDepth, d_mem_addr_t>;
