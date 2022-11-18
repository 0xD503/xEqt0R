#ifndef __CPU_H__
#define __CPU_H__

#include <cstdint>
#include <unordered_map>

#include "arch.hpp"
#include "device.hpp"
#include "instructions/instruction.hpp"
#include "instructions/isa.hpp"
#include "instructions/switches.hpp"
#include "memory_bus.hpp"
#include "register_file.hpp"


template<typename T, typename M, typename D>
class CPU : public Device {
    public:
        explicit CPU(MemoryBus<T, M, D>& instrMemBus, MemoryBus<T, D, M>& dataMemBus);
        virtual ~CPU();

        void cycle (void);
        // virtual void run (void) override;
        // virtual void stop (void) override;

    protected:
        RegisterFile<T> _registerFile;
        Register<T> _flags;

        MemoryBus<T, M, D>& _instrMemBus;
        MemoryBus<T, D, M>& _dataMemBus;

    protected:
        EncodedInstruction _fetch (void) const;
        Instruction _decode (EncodedInstruction encodedInstr) const;
        void _execute (Instruction instr, EncodedInstruction encodedInstr);
        //void _writeBack (word result);

    private:
        // word __readInstructionMemory (word addr);
        // void __writeInstructionMemory (word addr, word data);
        // word __readDataMemory (word addr);
        // void __writeDataMemory (word addr, word data);

        INSTR_TYPE __decodeOpcode (EncodedInstruction encodedInstr) const;

        bool __checkCondition (uint_fast8_t cond) const;
        void __executeALUOp (EncodedInstruction encodedInstr, Instruction instr);
        void __executeMemOp (EncodedInstruction encodedInstr, Instruction instr);
        void __executeFlowCtrlOp (EncodedInstruction encodedInstr, Instruction instr);

        void __writeBack (Registers targetRegID, word result);

    private:
        //
};


#endif // __CPU_H__
