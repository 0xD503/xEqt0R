#ifndef SOC_H_
#define SOC_H_

#include "cpu.hpp"
#include "memory.hpp"
#include "x_memory_bus.hpp"
//#include <cstddef>


template<typename T, typename M, typename D>
class SoC {
    public:
        static_assert(sizeof(i_mem_addr_t) <= sizeof(Register<T>), "size of " \
                                                             "addr should not "\
                                                             "be more than "\
                                                             "reg size");
        static_assert(sizeof(d_mem_addr_t) <= sizeof(Register<T>), "size of " \
                                                             "addr should not "\
                                                             "be more than "\
                                                             "reg size");

        explicit SoC(size_t instrMemLen, size_t dataMemLen);
        virtual ~SoC(void);


        // inline size_t getInstructionMemorySize (void) const
        // {
        //     return (_memory.getSize());
        // }
        // inline size_t getInstructionMemoryLength (void) const
        // {
        //     return (_memory.getLength());
        // }

        void run (void);

    protected:
        CPU<T, M, D> _cpu;
        Memory<M> _instructionMemory;
        Memory<D> _dataMemory;
        XMemoryBus<T, M, D> _instrMemoryBus;
        XMemoryBus<T, D, M> _dataMemoryBus;

    private:
        //
};


#endif // SOC_H_
