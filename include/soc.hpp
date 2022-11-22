#ifndef SOC_H_
#define SOC_H_

#include "cpu.hpp"
#include "memory.hpp"
#include "settings.hpp"
#include "x_memory_bus.hpp"
//#include <cstddef>


template<typename T, typename M, typename D>
class SoC {
    public:
        static_assert(sizeof(M) <= sizeof(Register<T>), "size of " \
                      "addr should not "                                \
                      "be more than "                                   \
                      "reg size");
        static_assert(sizeof(D) <= sizeof(Register<T>), "size of " \
                      "addr should not "                                \
                      "be more than "                                   \
                      "reg size");

        explicit SoC(size_t instrMemLen, size_t dataMemLen,
                     int argc, char *argv[]);
        virtual ~SoC(void);


        inline bool isFailed() const { return (__failed); }
        // inline size_t getInstructionMemorySize (void) const
        // {
        //     return (_memory.getSize());
        // }
        // inline size_t getInstructionMemoryLength (void) const
        // {
        //     return (_memory.getLength());
        // }

        virtual int run (void);

    protected:
        bool __failed;

    private:
        CPU<T, M, D> __cpu;
        Memory<M> __instructionMemory;
        Memory<D> __dataMemory;
        XMemoryBus<T, M, D> __instrMemoryBus;
        XMemoryBus<T, D, M> __dataMemoryBus;
        Settings<M> __settings;
};


#endif // SOC_H_
