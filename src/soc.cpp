#include "soc.hpp"


template<typename T, typename M, typename D>
SoC<T, M, D>::SoC(size_t instrMemLen, size_t dataMemLen) :
    _cpu(_instrMemoryBus, _dataMemoryBus),
    _instructionMemory(instrMemLen), _dataMemory(dataMemLen),
    _instrMemoryBus(_cpu, _instructionMemory),
    _dataMemoryBus(_cpu, _dataMemory)
{
    //
}

template<typename T, typename M, typename D>
SoC<T, M, D>::~SoC(void)
{
    //
}


template<typename T, typename M, typename D>
void SoC<T, M, D>::run (void)
{
    //
}


/// Explicit template instantiation. It is done in order to keep template
/// implementation separately from its declaration
//template class SoC<word, size_t>;
template class SoC<word, word, word>;
//template class SoC<word, i_mem_addr_t, d_mem_addr_t>;
//template class SoC<word, d_mem_addr_t>;
