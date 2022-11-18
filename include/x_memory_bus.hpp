#ifndef __X_MEMORY_BUS_H__
#define __X_MEMORY_BUS_H__

#include "memory_bus.hpp"


template<typename T, typename M, typename D>
class XMemoryBus : public MemoryBus<T, M, D> {
    public:
        explicit XMemoryBus(CPU<T, M, D> &cpu, Memory<M> &memory);
        ~XMemoryBus();

    protected:
        //

    private:
        //
};


#endif // __X_MEMORY_BUS_H__
