#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_HPP__

#include "arch.hpp"
#include "instructions/switches.hpp"


/// Mode header
struct __attribute__((packed)) ModeHead {
    word mode     : 1;
};  /// 1 bit here


/// Standart mode header declarations
struct __attribute__((packed)) ConditonHeadStd {
    struct ModeHead modeHead;
    word condition : CONDITION_FLAGS::NUM;
};  /// 5 bits here

/// Conditional operations header
struct __attribute__((packed)) OpCodeHeadStd {
    struct ConditonHeadStd condHead;
    word opCode   : 4;
};  /// 9 bits here

struct __attribute__((packed)) TargetRegHeadStd {
    struct OpCodeHeadStd opCodeHead;
    word targetReg  : arch::REGISTERS_POWER; /// need for most of the instrs
};  /// 17 bits here


/// Data Processing instructions headers
struct __attribute__((packed)) DataProcTypeHeadStd {
    struct TargetRegHeadStd destRegHead;
    word shamt    : 6;   /// shift amout
    word shift    : 1;   /// shifts always; 1 -shift operand, 0 -shift Imm/src_2
};  /// 24 bits here

struct __attribute__((packed)) ALUOpHeadStd {
    union __attribute__((packed)) Switches {
        struct __attribute__((packed)) Fields {
            word imm       : 1;  /// 1 - use immediate; 0 - use srcReg_2
            //word aluOpType : 2;  /// (logical ^ floating ^ !arithmetical)  op. type
            word logical   : 1;  ///
            word floating  : 1;  ///
            word negate    : 1;  ///
            word extended  : 2;  /// extended instructions support
        };

        struct Fields fields;
        word all : 6;
    };

    struct DataProcTypeHeadStd dataProc;
    union Switches sw;
};  /// 30 bits here

struct __attribute__((packed)) ALUOpStd {
    struct ALUOpHeadStd aluOpHead;
    word srcReg_1  : arch::REGISTERS_POWER;
};  /// 38 bits here

struct __attribute__((packed)) ALUOpRegStd {
    struct ALUOpStd aluOp;
    word srcReg_2 : arch::REGISTERS_POWER;   ///
};  /// 46 bits here

struct __attribute__((packed)) ALUOpImmStd {
    struct ALUOpStd aluOp;
    word immediate : 26; ///
};  /// 64 bits here

struct __attribute__((packed)) MovOpImmStd {
    struct ALUOpHeadStd aluOpType;
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
    struct __attribute__((packed)) _field {
        word mode : 1;
        word cond : CONDITION_FLAGS::NUM;
        word opCode : 4;
    };
    struct _field head;
    struct DataProcTypeHeadStd dataProc;
    struct ALUOpHeadStd aluOp;
    struct ShiftOpHeadStd shiftOp;

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
