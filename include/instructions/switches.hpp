#ifndef SWITCHES_H_
#define SWITCHES_H_

//


enum class CPU_MODE {
    DEFAULT = 0b0,
    EXTENDED = 0b1
};

enum class INSTR_TYPE {
    DATA_PROC = 0b0001,
    MEM_MANIP = 0b0010,
    FLOW_CONT = 0b0011,
    DEBUG = 0b1000,
    UNKNOWN
};

enum class ShiftType {
    LSL = 0b00,
    LSR = 0b01,
    ROT = 0b10,
    ASR = 0b11
};

enum class ALU_OP_TYPE {
    ARITHMETICAL = 0b00,
    LOGICAL = 0b10,
    FLOATING = 0b01
};

enum class BranchType {
    ABSOLUTE = 0b00,
    RELATIVE = 0b01,
    LINKED   = 0b10
};

/// CONDition flags
namespace CONDITION_FLAGS {
    static constexpr size_t NUM = 2;
    static constexpr uint_fast8_t MASK = 0b11;
    static constexpr uint_fast8_t N = 1 << 0;  /// negative flag
    static constexpr uint_fast8_t Z = 1 << 1;  /// zero flag
    //static constexpr uint_fast8_t C = 1 << 2;  /// carry flag
    static constexpr uint_fast8_t CONDITIONAL = 1 << 3;  /// 1 - cond. op, 0 - no cond.
}

/// SWitChes
namespace ALU_SWITCHES {
    // static constexpr size_t NUM = 8;
    // static constexpr uint_fast8_t N = 1 << 0;  /// ~negate/negate
    // static constexpr uint_fast8_t E = 1 << 1;  /// ~extended set/extended
    // static constexpr uint_fast8_t L = 1 << 2;  /// ~logical(arithmetical)/Logical
    // static constexpr uint_fast8_t F = 1 << 3;  /// ~fl.p. arithm./floating arithm.
    // static constexpr uint_fast8_t A = 1 << 4;  /// ~extended/extended(additional)
    // static constexpr uint_fast8_t S = 1 << 5;  /// shift
    // static constexpr uint_fast8_t S1 = 1 << 6; /// shift left/right
    // static constexpr uint_fast8_t S2 = 1 << 7; /// rotate/arithm. shift right
    //static constexpr uint_fast8_t MUL_DIV_XOR = 0b10;
}


#endif // SWITCHES_H_
