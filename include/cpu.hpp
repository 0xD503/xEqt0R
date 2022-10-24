#ifndef __CPU_H__
#define __CPU_H__

#include "register.hpp"
#include "register_file.hpp"
#include "instruction.hpp"
#include "arch.hpp"



template<typename T>
class CPU {
    public:

        static_assert(sizeof(i_mem_addr_t) <= sizeof(Register<T>), "size of addr " \
                                                             "should not be "\
                                                             "more than reg "\
                                                             "size");
        static_assert(sizeof(d_mem_addr_t) <= sizeof(Register<T>), "size of addr " \
                                                             "should not be "\
                                                             "more than reg "\
                                                             "size");

        explicit CPU(void);
        virtual ~CPU(void);

        void run (void);

    protected:
        bool _running;
        RegisterFile<T> _registerFile;

        Instruction _fetch (addr_t addr);
        void _decode (Instruction instr);
        void _execute (void);
        void _writeBack (void);

    private:
        //
};


#endif // __CPU_H__
