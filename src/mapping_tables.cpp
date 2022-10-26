//#include "mapping_tables.hpp"

#include "instruction.hpp"


using namespace ALU_SWITCHES;

/// Mapping table between Data Processing Instructions and their switches
static const std::map<uint_fast8_t, INSTRUCTION> DPI_CorrespondeceTable = {
    {~N | ~E | ~L | ~F | ~A | ~S | ~S1 | ~S2, INSTRUCTION::ADD},
    {~N | ~E | ~L | ~F | ~A |  S | ~S1 |  S2, INSTRUCTION::ASR},
    {~N | ~E | ~L |  F | ~A | ~S | ~S1 | ~S2, INSTRUCTION::FADD},
    {~N | ~E |  L | ~F | ~A | ~S | ~S1 | ~S2, INSTRUCTION::ORR},
    {~N | ~E |  L | ~F |  A | ~S | ~S1 | ~S2, INSTRUCTION::AND},
    {~N |  E | ~L | ~F | ~A | ~S | ~S1 | ~S2, INSTRUCTION::MUL},
    {~N |  E | ~L |  F | ~A | ~S | ~S1 | ~S2, INSTRUCTION::FMUL},
    {~N |  E |  L | ~F | ~A | ~S | ~S1 | ~S2, INSTRUCTION::XOR},
    { N | ~E | ~L | ~F | ~A | ~S | ~S1 | ~S2, INSTRUCTION::SUB},
    { N | ~E | ~L | ~F | ~A |  S | ~S1 | ~S2, INSTRUCTION::LSL},
    { N | ~E | ~L | ~F | ~A |  S | ~S1 |  S2, INSTRUCTION::LSR},
    { N | ~E | ~L | ~F | ~A |  S |  S1 | ~S2, INSTRUCTION::ROT},
    { N | ~E | ~L | ~F |  A | ~S | ~S1 | ~S2, INSTRUCTION::MOV},
    { N | ~E | ~L |  F | ~A | ~S | ~S1 | ~S2, INSTRUCTION::FSUB},
    { N | ~E |  L | ~F | ~A | ~S | ~S1 | ~S2, INSTRUCTION::NOR},
    { N | ~E |  L | ~F |  A | ~S | ~S1 | ~S2, INSTRUCTION::NAND},
    { N |  E | ~L | ~F | ~A | ~S | ~S1 | ~S2, INSTRUCTION::DIV},
    { N |  E | ~L |  F | ~A | ~S | ~S1 | ~S2, INSTRUCTION::FDIV},
    { N |  E |  L | ~F | ~A | ~S | ~S1 | ~S2, INSTRUCTION::NXOR},
    { N |  E |  L | ~F |  A | ~S | ~S1 | ~S2, INSTRUCTION::NEG},
};


//
