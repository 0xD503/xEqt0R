#ifndef __CPU_H__
#define __CPU_H__

#include <cstdint>
#include <unordered_map>

#include "arch.hpp"
#include "instructions/instruction.hpp"
#include "instructions/isa.hpp"
#include "instructions/switches.hpp"
#include "register_file.hpp"


template<typename T>
class CPU {
    public:
        explicit CPU(void);
        virtual ~CPU(void);

        void run (void);

    protected:
        bool _running;

        EncodedInstruction_t _encodedInstruction;
        INSTRUCTION _instruction;
        word _result;
        RegisterFile<T> _registerFile;

    protected:
        word _flags;

    protected:
        void _fetch (void);
        void _decode (void);
        void _execute (void);
        void _writeBack (void);

    private:
        INSTR_TYPE __decodeOpcode (void);
        void __prepareDatapath (void);

        //INSTRUCTION __getInstruction(uint_fast8_t)

    private:
        /// Mapping table between Data Processing Instructions and their switches
        static const std::unordered_map<uint_fast8_t,
                                        INSTRUCTION> __DPI_MappingTable;
};


#endif // __CPU_H__
