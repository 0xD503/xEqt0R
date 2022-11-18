#include "x_memory_bus.hpp"


template<typename T, typename M, typename D>
XMemoryBus<T, M, D>::XMemoryBus(CPU<T, M, D>& cpu, Memory<M>& memory) :
    MemoryBus<T, M, D>(cpu, memory) {
    //
}

template<typename T, typename M, typename D>
XMemoryBus<T, M, D>::~XMemoryBus() {
    //
}


template class XMemoryBus<word, word, word>;
//template class XMemoryBus<word, d_mem_addr_t>;
