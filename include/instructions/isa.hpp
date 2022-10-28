#ifndef __ISA_HPP__
#define __ISA_HPP__


enum class INSTRUCTION {
    /// Data proc
    AND = 1, NAND,
    ORR, NOR,
    XOR, NXOR,
    ADD, SUB,
    MUL, DIV,
    FADD, FSUB, FMUL, FDIV,  /// FPU
    NEG,                     /// binary negation
    LSL, LSR,                /// shift
    ROT,                     /// rotate
    ASR,                     /// arithmetic shift right
    MOV,
    /// Mem manip
    LDR, STR,
    /// FLOW Control
    B,
    /// Other
    NOP,

    UNKNOWN
};


#endif // __ISA_HPP__
