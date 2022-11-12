#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_HPP__

//#include <cstdint>

#include "arch.hpp"
#include "instructions/switches.hpp"


//using namespace arch;

/// Mode header
struct __attribute__((packed)) ModeHead {
    word mode     : 1;
    //word reserved : 1;
};


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
    struct DataProcTypeHeadStd dataProcType;
    word imm       : 1;  /// 1 - use immediate; 0 - use srcReg_2
    word aluOpType : 2;  /// (logical ^ floating ^ !arithmetical)  op. type
    word negate    : 1;  ///
    word extended  : 2;  /// extended instructions support
};  /// 30 bits here

struct __attribute__((packed)) ALUOpStd {
    struct ALUOpHeadStd aluOpType;
    word srcReg_1  : arch::REGISTERS_POWER;
    word srcReg_2 : arch::REGISTERS_POWER;   ///
};  /// 46 bits here

struct __attribute__((packed)) ALUOpImmStd {
    struct ALUOpHeadStd aluOpType;
    word srcReg_1  : arch::REGISTERS_POWER;
    word immediate : 26; ///
};  /// 64 bits here

// struct __attribute__((packed)) MovOpImmStd {
//     struct ALUOpHeadStd aluOpType;
//     word immediate : 34;
// };

struct __attribute__((packed)) ShiftOpHeadStd {
    struct DataProcTypeHeadStd dataProcType;
    word shiftType : 2;
    word srcReg_1  : arch::REGISTERS_POWER;    /// operand that will be shifted
};  /// 32 bits here



/// Memory Manipulating instructions
struct __attribute__((packed)) MemoryManipStd {
    //struct OpCodeHeadStd opCodeHead;
    struct TargetRegHeadStd targetRegHead;
    word memAddr    : arch::REGISTERS_POWER;
};  /// 25 bits here



/// Flow Control instructions
struct __attribute__((packed)) FlowControlHeadStd {
    struct TargetRegHeadStd addrRegHead;
    //
};  /// 17 bits here




union EncodedInstruction {
    struct _field {
        word mode : 1;
        word cond : CONDITION_FLAGS::NUM;
        word opCode : 4;
        ////word targetReg :
//        word mode       : 1;    /// 20
//        word reserved_4 : 1;    /// 21
//        word condition  : 4;    /// 9
//        word reserved_2 : 2;    /// 11
//        word opCode     : 4;    /// 4
//        word reserved_1 : 1;    /// 5
//        word destReg    : 5;    /// 46
//        word shamt      : 6;    /// 35
//        word shift      : 2;    /// 29
//        word reserved_6 : 1;    /// 36
//        word immediate  : 9;    /// 64
//        word switches   : 5;    /// 16
//        word reserved_3 : 2;    /// 18
        // word srcReg     : 5;    /// 51
        // word srcReg_2   : 5;    ///
        // word misc       : 2;    /// 23
        // word reserved_5 : 4;    /// 27
        // word opCode_2   : 4;    /// 40
        // word reserved_7 : 1;    /// 41
    };
    struct _field field;
    word data;


    /// ctor/dtor
    explicit EncodedInstruction(void) = default;
    ~EncodedInstruction(void) = default;
};
/// TODO: PACK STRUCT!!!



// struct __attribute__((packed)) ArithmOpStd {
//     struct ALUOpHeadStd aluOpType;
//     word srcReg_1 : 5;
//     word srcReg_2 : 5;   /// 36 bits here
// };

// struct __attribute((packed)) DataProcLogicalHeadStd {
//     struct ALUOpHeadStd aluOpType;
//     word srcReg_1 : 5;
//     word srcReg_2 : 5;   /// 36 bits here
// };

// struct __attribute__((packed)) DataProcFloatingHeadStd {
//     struct ALUOpHeadStd aluOpType;
//     word srcReg_1 : 5;
//     word srcReg_2 : 5;   /// 36 bits here
// };







// struct __attribute__((packed)) DataProcessingHeadStd {
//     struct OpCodeHeadStd opCodeHead;
//     //word shift    : 1;   /// shifts always; 1 - shift op, 0 - shift Imm/src_2
//     word switches : 5;   ///
//     word destReg  : 5;   ///  bits here
// };

// struct __attribute__((packed)) ShiftOpHeadStd {
//     struct DataProcessingHeadStd dataProcHead;
//     word shiftType : 2;
//     word srcReg_1  : 5;   ///  bits here
// };

// struct __attribute__((packed)) ShiftImmOpHeadStd {
//     struct DataProcessingHeadStd dataProcHead;
//     word shiftType : 2;
//     word srcReg_1  : 5;   /// 34 bits here
//     word immediate : 24;  ///
// };

//struct __attribute__((packed)) LogicalProcessHeadStd {
    //struct DataProcessingHeadStd dataProcHead;
    //
//};






typedef union EncodedInstruction EncodedInstruction_t;


static_assert(sizeof(EncodedInstruction_t) == sizeof(word), "instruction should "\
                                                            "be word sized");


#endif // __INSTRUCTION_HPP__
