#ifndef __ISA_HPP__
#define __ISA_HPP__


enum class Instruction {
    /// Data proc
    AND = 1, NAND,
    ORR, NOR,
    XOR, NXOR,
    ADD, SUB,
    MUL, DIV,
    FADD, FSUB, FMUL, FDIV, /// FPU
    NEG,                    /// binary negation
    LSL, LSR,               /// shift
    ROT,                    /// rotate
    ASR,                    /// arithmetic shift right
    MOV,
    /// FAST instructions
    MAX, MIN,
    POPCNT,
    /// Mem manip
    LDR, STR,
    WLDR, WSTR,             /// wide load/store (up to 256 regs)
    PUSH, POP,
    /// FLOW Control
    B, BR, BLX,
    CALL, RET,
    /// Other
    NOP,
    HALT,

    /// Exception
    FAULT,

    UNKNOWN
};


#endif // __ISA_HPP__
