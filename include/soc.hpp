#ifndef SOC_H_
#define SOC_H_

#include "cpu.hpp"
#include "memory.hpp"


template<typename T, typename M>
class SoC {
    public:
        explicit SoC<T, M>(size_t len);
        virtual ~SoC(void);


        void run (void);

    protected:
        CPU<T> _cpu;
        Memory<M> _memory;

    private:
        //
};


#endif // SOC_H_
