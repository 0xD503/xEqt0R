#ifndef SOC_H_
#define SOC_H_

#include "cpu.hpp"
#include "memory.hpp"
//#include <cstddef>


template<typename T, typename M>
class SoC {
    public:
        explicit SoC(size_t len);
        virtual ~SoC(void);


        inline size_t getInstructionMemorySize (void)
        {
            return (_memory.getSize());
        }
        inline size_t getInstructionMemoryLength (void)
        {
            return (_memory.getLength());
        }

        void run (void);

    protected:
        CPU<T> _cpu;
        Memory<M> _memory;

    private:
        //
};


#endif // SOC_H_
