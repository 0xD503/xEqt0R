#include "memory_bus.hpp"


template<typename T, typename M, typename D>
MemoryBus<T, M, D>::MemoryBus(CPU<T, M, D> &cpu, Memory<M> &memory) :
    _cpu(cpu), _memory(memory) {
    //
}

template<typename T, typename M, typename D>
MemoryBus<T, M, D>::~MemoryBus() {
    //
}


template<typename T, typename M, typename D>
bool MemoryBus<T, M, D>::readMemory (const size_t addr, T& dest) const {
    bool status = _memory.readWord(addr, dest);

    return (status);
}

template<typename T, typename M, typename D>
bool MemoryBus<T, M, D>::writeMemory (const size_t addr, T& data) const {
    bool status = _memory.writeWord(addr, data);

    return (status);
}


template class MemoryBus<word, word, word>;
//template class MemoryBus<word, d_mem_addr_t>;
