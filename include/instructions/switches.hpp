#ifndef SWITCHES_H_
#define SWITCHES_H_

//


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

enum class ALU_OP_TYPE {
    ARITHMETICAL = 0b00,
    LOGICAL = 0b10,
    FLOATING = 0b01
};

/// CONDition flags
namespace CONDITION_FLAGS {
    static constexpr uint_fast8_t N = 1 << 0;  /// negative flag
    static constexpr uint_fast8_t Z = 1 << 1;  /// zero flag
    static constexpr uint_fast8_t C = 1 << 2;  /// carry flag
    static constexpr uint_fast8_t V = 1 << 3;  /// overflow flag
};

/// SWitChes
namespace ALU_SWITCHES {
    static constexpr uint_fast8_t N = 1 << 0;  /// ~negate/negate
    static constexpr uint_fast8_t E = 1 << 1;  /// ~extended set/extended
    static constexpr uint_fast8_t L = 1 << 2;  /// ~logical(arithmetical)/Logical
    static constexpr uint_fast8_t F = 1 << 3;  /// ~fl.p. arithm./floating arithm.
    static constexpr uint_fast8_t A = 1 << 4;  /// ~extended/extended(additional)
    static constexpr uint_fast8_t S = 1 << 5;  /// shift
    static constexpr uint_fast8_t S1 = 1 << 6; /// shift left/right
    static constexpr uint_fast8_t S2 = 1 << 7; /// rotate/arithm. shift right
};


#endif // SWITCHES_H_
