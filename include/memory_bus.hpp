#ifndef __MEMORY_BUS_HPP__
#define __MEMORY_BUS_HPP__

#include "bus.hpp"
//#include "cpu.hpp"
#include "memory.hpp"


/// Forward declaration of CPU
template<typename T, typename M, typename D>
class CPU;


template<typename T, typename M, typename D>
class MemoryBus : public Bus {
    public:
        explicit MemoryBus(CPU<T, M, D>& cpu, Memory<M>& memory);
        virtual ~MemoryBus() = 0;


        virtual bool readMemory (const size_t addr, T& dest) const;
        virtual bool writeMemory (const size_t addr, T& data) const;

    protected:
        CPU<T, M, D>& _cpu;
        Memory<M>& _memory;

    private:
        //
};


#endif // __MEMORY_BUS_HPP__
