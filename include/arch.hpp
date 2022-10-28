#ifndef ARCH_H_
#define ARCH_H_

#include <cstddef>
#include <cstdint>


namespace arch {
    static constexpr size_t REGISTERS_POWER = 8;    /// 2^8 == 256 registers :-D
    static constexpr size_t REGISTERS_NUM = 1 << REGISTERS_POWER;    /// o_O
}


enum class REGISTERS {
    R0 = 0, R1 = 1, R2 = 2, R3 = 3, R4 = 4, R5 = 5, R6 = 6, R7 = 7,
    R8 = 8, R9 = 9, R10 = 10, R11 = 11, R12 = 12, R13 = 13, R14 = 14, R15 = 15,
    R16 = 16, R17 = 17, R18 = 18, R19 = 19, R20 = 20, R21 = 21, R22 = 22, R23 = 23,
    R24 = 24, R25 = 25, R26 = 26, R27 = 27, R28 = 28, LR = 29, SP = 30, PC = 31,
    RegsNumber = 32
};


/// TODO: make struct packed
struct Addr_s {
    uint64_t addr    : 32;
};


typedef uint16_t i_mem_addr_t;
typedef uint32_t d_mem_addr_t;
typedef struct Addr_s addr_t;
typedef uint64_t word;


#endif // ARCH_H_
