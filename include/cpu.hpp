#ifndef __CPU_H__
#define __CPU_H__

#include <cstddef>
#include <cstdint>
#include <unordered_map>

#include "arch.hpp"
#include "device.hpp"
#include "instructions/instruction.hpp"
#include "instructions/isa.hpp"
#include "instructions/switches.hpp"
#include "memory_bus.hpp"
#include "register.hpp"
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
        virtual EncodedInstruction _fetch () const;
        virtual Instruction _decode (EncodedInstruction encodedInstr) const;
        virtual void _execute (Instruction instr, EncodedInstruction encodedInstr);
        //void _writeBack (word result);
        virtual inline void _incrementPC () {
            _registerFile[static_cast<std::size_t>(Registers::PC)]++;
        }

    private:
        inline const Register<T>& __getCurrentPC () const {
            return (_registerFile[static_cast<std::size_t>(Registers::PC)]);
        }

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
