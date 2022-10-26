#ifndef SOC_H_
#define SOC_H_

#include "cpu.hpp"
#include "memory.hpp"
//#include <cstddef>


template<typename T, typename M>
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

        explicit SoC(size_t len);
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
        CPU<T> _cpu;
        Memory<M> _memory;

    private:
        //
};


#endif // SOC_H_
