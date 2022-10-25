#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

#include <cstdint>

#include "isa.hpp"


class Instruction {
    public:
        explicit Instruction(uint64_t instr) :
            _instruction(instr) { };
        //Instruction(void) :
          //  _instruction(0x00) { };


        //inline uint64_t getField (Field type) const
        inline uint64_t getField (void) const
        {
            return (_instruction);
        }

    protected:
        uint64_t _instruction;

    private:
        //
};


#endif // __INSTRUCTION_H__
