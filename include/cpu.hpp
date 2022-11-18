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
        EncodedInstruction _fetch (void) const;
        Instruction _decode (EncodedInstruction encodedInstr) const;
        void _execute (Instruction instr, EncodedInstruction encodedInstr);
        //void _writeBack (word result);

    private:
        word __readInstructionMemory (word addr);
        void __writeInstructionMemory (word addr, word data);
        word __readDataMemory (word addr);
        void __writeDataMemory (word addr, word data);

        INSTR_TYPE __decodeOpcode (EncodedInstruction encodedInstr) const;
//        void __prepareDatapath (EncodedInstruction encodedInstr);
//
        bool __checkCondition (uint_fast8_t cond) const;
        void __executeALUOp (EncodedInstruction encodedInstr, Instruction instr);
        void __executeMemOp (EncodedInstruction encodedInstr, Instruction instr);
        void __executeFlowCtrlOp (EncodedInstruction encodedInstr, Instruction instr);

        void __writeBack (Registers targetRegID, word result);

        //INSTRUCTION __getInstruction(uint_fast8_t)

    private:
        // /// Mapping table between Data Processing Instructions and their switches
        // static const std::unordered_map<uint_fast8_t,
        //                                 Instruction> __DPI_MappingTable;
};


#endif // __CPU_H__
