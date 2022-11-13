#ifndef __CPU_H__
#define __CPU_H__

#include <cstdint>
#include <unordered_map>

#include "arch.hpp"
#include "device.hpp"
#include "instructions/instruction.hpp"
#include "instructions/isa.hpp"
#include "instructions/switches.hpp"
#include "register_file.hpp"


template<typename T>
class CPU : public Device {
    public:
        explicit CPU(void);
        virtual ~CPU(void);

        void cycle (void);
        // virtual void run (void) override;
        // virtual void stop (void) override;

    protected:
        RegisterFile<T> _registerFile;
        Register<T> _flags;

    protected:
        EncodedInstruction _fetch (void);
        Instruction _decode (EncodedInstruction encodedInstr);
        word _execute (Instruction instr);
        void _writeBack (word result);

    private:
        INSTR_TYPE __decodeOpcode (EncodedInstruction encodedInstr);
        void __prepareDatapath (EncodedInstruction encodedInstr);

        //INSTRUCTION __getInstruction(uint_fast8_t)

    private:
        // /// Mapping table between Data Processing Instructions and their switches
        // static const std::unordered_map<uint_fast8_t,
        //                                 Instruction> __DPI_MappingTable;
};


#endif // __CPU_H__
