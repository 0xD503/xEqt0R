#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

#include <cstdint>

#include "arch.hpp"


enum class CPU_MODE {
    DEFAULT = 0,
    EXTENDED = 1
};

enum class INSTR_TYPE {
    DATA_PROC = 1,
    MEM_MANIP = 2,
    FLOW_CONT = 3,
    DEBUG = 8,
    UNKNOWN
};

/// CONDition flags
namespace CONDITION_FLAGS {
    static constexpr uint_fast8_t N = 1 << 0;  /// negative flag
    static constexpr uint_fast8_t Z = 1 << 1;  /// zero flag
    static constexpr uint_fast8_t C = 1 << 2;  /// carry flag
    static constexpr uint_fast8_t V = 1 << 3;  /// overflow flag
};

/// SWitChes
static constexpr uint_fast8_t L = 1 << 0;  /// ~logical(arithmetical)/Logical
static constexpr uint_fast8_t N = 1 << 0;  /// !
//namespace INSTRUCTIONS {
    //static
//}
// enum class INSTRUCTION {
//     /// Data proc
//     ADD = 1, SUB,
//     AND, OR,
//     MOV,
//     /// Mem manip
//     LDR, STR,
//     /// FLOW Control
//     B,

//     UNKNOWN
// };


union EncodedInstruction {
    struct _field {
        word mode       : 1;    /// 20
        word reserved_4 : 1;    /// 21
        word opCode     : 4;    /// 4
        word reserved_1 : 1;    /// 5
        word condition  : 4;    /// 9
        word reserved_2 : 2;    /// 11
        word switches   : 5;    /// 16
        word reserved_3 : 2;    /// 18
        word misc       : 2;    /// 23
        word reserved_5 : 4;    /// 27
        word shift      : 2;    /// 29
        word shamt      : 6;    /// 35
        word reserved_6 : 1;    /// 36
        word opCode_2   : 4;    /// 40
        word reserved_7 : 1;    /// 41
        word destReg    : 5;    /// 46
        word srcReg     : 5;    /// 51
        word immediate  : 14;   /// 64
    };
    struct _field field;
    word data;


    /// ctor/dtor
    explicit EncodedInstruction(void) = default;
    ~EncodedInstruction(void) = default;
};
/// TODO: PACK STRUCT!!!


typedef union EncodedInstruction EncodedInstruction_t;


static_assert(sizeof(EncodedInstruction_t) == sizeof(word), "instruction should "\
                                                            "be word sized");


#endif // __INSTRUCTION_H__
