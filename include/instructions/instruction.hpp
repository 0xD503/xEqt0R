#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_HPP__

#include "arch.hpp"
#include "instructions/switches.hpp"


/// Mode header
struct __attribute__((packed)) ModeFlag {
    word flag     : 1;
};  /// 1 bit here


/// Standart mode header declarations
struct __attribute__((packed)) ConditonFlagsStd {
    //struct ModeHead modeHead;
    word flags : CONDITION_FLAGS::NUM;
};  /// 4 bits here

/// Conditional operations header
struct __attribute__((packed)) OpCodeStd {
    //struct ConditonHeadStd condHead;
    word code   : 4;
};  /// 4 bits here

union __attribute__((packed)) ALUSwitches {
    struct __attribute__((packed)) Switches {
        word negate    : 1;  /// 1 - negation used, 0 - don't negate
        /// (logical ^ arithmetical) | floating)  op. type
        word logical   : 1;  /// 1 - logical, 0 - arithmetical
        word floating  : 1;  /// 1 - real numbers, 0 - integers
        word extended  : 2;  /// extended instructions support
    };

    struct Switches flags;
    word all : 5;
};  /// 5 bits here


struct __attribute__((packed)) InstructionHeadStd {
    struct ModeFlag mode;
    struct ConditonFlagsStd cond;
    struct OpCodeStd opCode;
};  /// 9 bits here

struct __attribute__((packed)) TargetRegHeadStd {
    struct InstructionHeadStd instrHead;
    word reg  : arch::REGISTERS_POWER; /// need for most of the instrs
};  /// 17 bits here


/// Data Processing instructions headers
struct __attribute__((packed)) DataProcTypeHeadStd {
    struct TargetRegHeadStd destRegHead;
    word shamt    : 6;   /// shift amout
    word shift    : 1;   /// shifts always; 1 -shift operand, 0 -shift Imm/src_2
};  /// 24 bits here

struct __attribute__((packed)) ALUOpHeadStd {
    struct DataProcTypeHeadStd dataProc;
    word imm       : 1;  /// 1 - use immediate; 0 - use srcReg_2
    union ALUSwitches switches;
};  /// 30 bits here

struct __attribute__((packed)) ALUOpStd {
    struct ALUOpHeadStd aluOpHead;
    word srcReg_1  : arch::REGISTERS_POWER;
};  /// 38 bits here

struct __attribute__((packed)) ALUOpRegStd {
    struct InstructionHeadStd head;
    word targetReg : arch::REGISTERS_POWER;
    word shamt     : 6;   /// shift amout
    word shift     : 1;   /// shifts always; 1 -shift operand, 0 -shift Imm/src_2
    word imm       : 1;  /// 1 - use immediate; 0 - use srcReg_2
    union ALUSwitches switches;
    word srcReg_1  : arch::REGISTERS_POWER;
    word srcReg_2  : arch::REGISTERS_POWER;   ///
};  /// 46 bits here

struct __attribute__((packed)) ALUOpImmStd {
    //struct InstructionHeadStd head;
    word head      : 9;
    word targetReg : arch::REGISTERS_POWER;
    word shamt     : 6;   /// shift amout
    word shift     : 1;   /// shifts always; 1 -shift operand, 0 -shift Imm/src_2
    word imm       : 1;  /// 1 - use immediate; 0 - use srcReg_2
    //union ALUSwitches switches;
    word switches  : 5;
    word srcReg_1  : arch::REGISTERS_POWER;
    word immediate : 26; ///
};  /// 64 bits here

// struct __attribute__((packed)) ALUOpRegStd {
//     struct ALUOpStd aluOp;
//     word srcReg_2  : arch::REGISTERS_POWER;   ///
// };  /// 46 bits here

// struct __attribute__((packed)) ALUOpImmStd {
//     struct ALUOpStd aluOp;
//     word immediate : 26; ///
// };  /// 64 bits here

struct __attribute__((packed)) MovOpImmStd {
    struct ALUOpHeadStd aluOpHead;
    word immediate : 34;
};  /// 64 bits here


struct __attribute__((packed)) ShiftOpHeadStd {
    struct DataProcTypeHeadStd dataProcType;
    word shiftType : 2;
    word srcReg_1  : arch::REGISTERS_POWER;    /// operand that will be shifted
};  /// 34 bits here



/// Memory Manipulating instructions
struct __attribute__((packed)) MemoryManipStd {
    //struct OpCodeHeadStd opCodeHead;
    struct TargetRegHeadStd targetRegHead;
    word memAddr    : arch::REGISTERS_POWER;
};  ///  bits here



/// Flow Control instructions
struct __attribute__((packed)) FlowControlHeadStd {
    struct TargetRegHeadStd addrRegHead;
    //
};  ///  bits here




union EncodedInstruction {
    struct InstructionHeadStd headStd;
    struct DataProcTypeHeadStd dataProcStd;
    struct ALUOpHeadStd aluOpStd;
    struct ALUOpRegStd aluOpRegStd;
    struct ALUOpImmStd aluOpImmStd;
//    struct MovOpImmStd movOpImmStd;
    struct ShiftOpHeadStd shiftOpStd;

    // struct MemoryManipStd memoryManipI;
    // struct FlowControlHeadStd flowCtrlI;
    word __data;


    /// ctor/dtor
    explicit EncodedInstruction(void) = default;
    ~EncodedInstruction(void) = default;
};



typedef union EncodedInstruction EncodedInstruction_t;


static_assert(sizeof(EncodedInstruction_t) == sizeof(word), "instruction should "\
                                                            "be word sized");


#endif // __INSTRUCTION_HPP__
