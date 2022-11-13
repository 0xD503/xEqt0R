#include "cpu.hpp"
#include <cstdint>


template<typename T>
CPU<T>::CPU(void) :
    Device(),
    _registerFile(),
    _flags()
{
    //
}

template<typename T>
CPU<T>::~CPU(void) {
    //
}


template<typename T>
void CPU<T>::cycle (void) {
    //Device::run();

    EncodedInstruction encodedInstr = _fetch();
    Instruction decodedInstr = _decode(encodedInstr);
    word result = _execute(decodedInstr);
    _writeBack(result);
}

// template<typename T>
// void CPU<T>::stop (void) {
//     Device::stop();
// }


template<typename T>
EncodedInstruction CPU<T>::_fetch (void) {
    EncodedInstruction encodedInstruction;

    /// Send signal throug memory bus to fetch instruction
    /// Design patter: ???
    /// TODO: increment PC during FETCH or EXECUTE???
    //_encodedInstruction.data = instrMemory[pc];
    //_encodedInstruction.data = instrMemory[pc++];

    return (encodedInstruction);
}

template<typename T>
Instruction CPU<T>::_decode (EncodedInstruction encodedInstr) {
    Instruction instruction;
    INSTR_TYPE type = __decodeOpcode(encodedInstr);

    switch (type) {
        case INSTR_TYPE::DATA_PROC: {
            /// TODO:
            /// Check op code
            if (encodedInstr.dataProc.shift == 1) {    /// shift type op
                ShiftType shtType = static_cast<ShiftType>(encodedInstr.shiftOp.shiftType);

                switch (shtType) {
                    case ShiftType::LSL: {
                        instruction = Instruction::LSL;
                        break;
                    }
                    case ShiftType::LSR: {
                        instruction = Instruction::LSR;
                        break;
                    }
                    case ShiftType::ROT: {
                        instruction = Instruction::ROT;
                        break;
                    }
                    case ShiftType::ASR: {
                        instruction = Instruction::ASR;
                        break;
                    }

                    default: {
                        //static_assert(false, "wrong shift type");
                        break;
                    }
                }
            }
            else {                                      /// ALU operation
                uint_fast8_t extension;// = encodedInstr.aluOpHead.switches.fields;
                // instruction = __DPI_MappingTable.at(switches);
                if (encodedInstr.aluOp.sw.fields.negate == 1) {
                    if (encodedInstr.aluOp.sw.fields.logical == 1) {
                        if (encodedInstr.aluOp.sw.fields.floating == 0) {
                            extension = encodedInstr.aluOp.sw.fields.extended;
                            switch (extension) {
                                case 0b00: {
                                    instruction = Instruction::NOR;
                                    break;
                                }
                                case 0b01: {
                                    instruction = Instruction::NAND;
                                    break;
                                }
                                case 0b10: {
                                    instruction = Instruction::NXOR;
                                    break;
                                }
                                case 0b11: {
                                    instruction = Instruction::NEG;
                                    break;
                                }

                                default: {
                                    instruction = Instruction::UNKNOWN;
                                    break;
                                }
                            }
                        }
                        else {
                            instruction = Instruction::UNKNOWN;
                        }
                    }
                    else {
                        //
                    }
                }
                else {
                    //
                }
//     {~N | ~E | ~L | ~F | ~A, Instruction::ADD},
//     {~N | ~E | ~L |  F | ~A, Instruction::FADD},
//     {~N | ~E |  L | ~F | ~A, Instruction::ORR},
//     {~N | ~E |  L | ~F |  A, Instruction::AND},
//     {~N |  E | ~L | ~F | ~A, Instruction::MUL},
//     {~N |  E | ~L |  F | ~A, Instruction::FMUL},
//     {~N |  E |  L | ~F | ~A, Instruction::XOR},
//     { N | ~E | ~L | ~F | ~A, Instruction::SUB},
//     { N | ~E | ~L | ~F |  A, Instruction::MOV},
//     { N | ~E | ~L |  F | ~A, Instruction::FSUB},
///     { N | ~E |  L | ~F | ~A, Instruction::NOR},
///     { N | ~E |  L | ~F |  A, Instruction::NAND},
//     { N |  E | ~L | ~F | ~A, Instruction::DIV},
//     { N |  E | ~L |  F | ~A, Instruction::FDIV},
///     { N |  E |  L | ~F | ~A, Instruction::NXOR},
///     { N |  E |  L | ~F |  A, Instruction::NEG},
            }
            break;
        }
        case INSTR_TYPE::MEM_MANIP: {
            /// TODO:
            //
            break;
        }
        case INSTR_TYPE::FLOW_CONT: {
            /// TODO:
            //
            break;
        }
        case INSTR_TYPE::DEBUG: {
            /// TODO:
            //
            break;
        }

        case INSTR_TYPE::UNKNOWN: {
            /// TODO:
            //
            break;
        }


        default: {
            /// TODO: unknow type
            break;
        }
    }


    return (instruction);
}

template<typename T>
word CPU<T>::_execute (Instruction instr) {
    word result;

    /// TODO: ADD flags changing on processing data
    switch (instr) {
        case Instruction::ADD: {
            // uint_fast8_t cond = _encodedInstruction.field.condition;
            // if (cond != 0)
            // {
            //     /// TODO: break if condition doesn't allow to execute
            // }
            //_result = _registerFile[??] + _registerFile[??];
            break;
        }
        // case Instruction::SUB: {
        //     //std::cout << "SUBstracting something" << std::endl;
        //     uint_fast8_t cond = _encodedInstruction.field.condition;
        //     _result = _registerFile[??] - _registerFile[??];
        //     break;
        // }
        // case Instruction::AND: {
        //     //std::cout << "ANDing something" << std::endl;
        //     _result = _registerFile[??] & _registerFile[??];
        //     break;
        // }
        // case Instruction::OR: {
        //     //std::cout << "ORing something" << std::endl;
        //     _result = _registerFile[??] | _registerFile[??];
        //     break;
        // }
        // case Instruction::B:Instruction {
        //     /// TODO: Undone
        //     //std::cout << "Branching somewhere" << std::endl;
        //     uint_fast8_t cond = _encodedInstruction.field.condition;
        //     //pc = pc + 2;
        //     break;
        // }
        // case Instruction::MOV: {
        //     /// TODO: Undone
        //     //std::cout << "MOVing immediate to reg" << std::endl;
        //     uint_fast8_t cond = _encodedInstruction.field.condition;
        //     _registerFile[??] = ??;
        //     break;
        // }
        // case Instruction::LDR: {
        //     /// TODO: Undone
        //     //std::cout << "LoaDing something from mem to Reg" << std::endl;
        //     _registerFile[??] = ??;
        //     break;
        // }
        // case Instruction::STR: {
        //     /// TODO: Undone
        //     //std::cout << "SToring something from Reg to mem" << std::endl;
        //     ?? = _registerFile[??];
        //     break;
        // }

        default: {
            /// TODO: Undone wrong instruction handling
            //std::cout << "!!!!!!!!!!!!UNKNOWN INSTRUCTION!!!!!!!!!!!!!!" << std::endl;
            break;
        }
    }

    return (result);
}

template<typename T>
void CPU<T>::_writeBack (word result)
{
    /// TODO: undone
//    _registerFile[??] = _result;
}



/// private section
template<typename T>
INSTR_TYPE CPU<T>::__decodeOpcode (EncodedInstruction encodedInstr) {
    INSTR_TYPE type = INSTR_TYPE::UNKNOWN;

    switch ((CPU_MODE) encodedInstr.head.mode) {
        case CPU_MODE::DEFAULT: {
            type = (INSTR_TYPE) encodedInstr.head.opCode;
            break;
        }
        case CPU_MODE::EXTENDED: {
            /// TODO: NOT SUPPORTED
            //type =
            break;
        }

        default: {
            /// TODO: NOT SUPPORTED
            break;
        }
    }

    return (type);
}


template<typename T>
void CPU<T>::__prepareDatapath (EncodedInstruction encodedInstr) {
    /// TODO: check if its shift operation first
    //DataProcTypeHeadStd dataProcType =
    //_encodedInstruction
    //uint_fast8_t sw = _encodedInstruction.field.sw;
    //_instruction = __DPI_MappingTable.at(sw);


    // if (sw & ALU_SW::A) {
    //     if (switches & ALU_SWITCHES::E) {
    //         _instruction = Instruction::NEG;    /// binary negation
    //     }
    //     else {
    //         if (switches & ALU_SWITCHES::N) {
    //             _instruction = Instruction::NAND;
    //         }
    //         else {
    //             _instruction = Instruction::AND;
    //         }
    //     }
    // }
    // else {
    //     //
    // }
}


/// private data

// /// Mapping table between Data Processing Instructions and their switches
// template<typename T>
// const std::unordered_map<uint_fast8_t, Instruction> CPU<T>::__DPI_MappingTable = {
//     {~N | ~E | ~L | ~F | ~A, Instruction::ADD},
//     {~N | ~E | ~L |  F | ~A, Instruction::FADD},
//     {~N | ~E |  L | ~F | ~A, Instruction::ORR},
//     {~N | ~E |  L | ~F |  A, Instruction::AND},
//     {~N |  E | ~L | ~F | ~A, Instruction::MUL},
//     {~N |  E | ~L |  F | ~A, Instruction::FMUL},
//     {~N |  E |  L | ~F | ~A, Instruction::XOR},
//     { N | ~E | ~L | ~F | ~A, Instruction::SUB},
//     { N | ~E | ~L | ~F |  A, Instruction::MOV},
//     { N | ~E | ~L |  F | ~A, Instruction::FSUB},
//     { N | ~E |  L | ~F | ~A, Instruction::NOR},
//     { N | ~E |  L | ~F |  A, Instruction::NAND},
//     { N |  E | ~L | ~F | ~A, Instruction::DIV},
//     { N |  E | ~L |  F | ~A, Instruction::FDIV},
//     { N |  E |  L | ~F | ~A, Instruction::NXOR},
//     { N |  E |  L | ~F |  A, Instruction::NEG},
// };



/*
    {~N | ~E | ~L | ~F | ~A |  S | ~S1 |  S2, Instruction::ASR},   //
    { N | ~E | ~L | ~F | ~A |  S | ~S1 | ~S2, Instruction::LSL},   //
    { N | ~E | ~L | ~F | ~A |  S | ~S1 |  S2, Instruction::LSR},   //
    { N | ~E | ~L | ~F | ~A |  S |  S1 | ~S2, Instruction::ROT},   //

const std::unordered_map<uint_fast8_t, Instruction> CPU<T>::__DPI_MappingTable = {
    {~N | ~E | ~L | ~F | ~A | ~S | ~S1 | ~S2, Instruction::ADD},
//     {~N | ~E | ~L | ~F | ~A |  S | ~S1 |  S2, Instruction::ASR},   //
    {~N | ~E | ~L |  F | ~A | ~S | ~S1 | ~S2, Instruction::FADD},
    {~N | ~E |  L | ~F | ~A | ~S | ~S1 | ~S2, Instruction::ORR},
    {~N | ~E |  L | ~F |  A | ~S | ~S1 | ~S2, Instruction::AND},
    {~N |  E | ~L | ~F | ~A | ~S | ~S1 | ~S2, Instruction::MUL},
    {~N |  E | ~L |  F | ~A | ~S | ~S1 | ~S2, Instruction::FMUL},
    {~N |  E |  L | ~F | ~A | ~S | ~S1 | ~S2, Instruction::XOR},
    { N | ~E | ~L | ~F | ~A | ~S | ~S1 | ~S2, Instruction::SUB},
//     { N | ~E | ~L | ~F | ~A |  S | ~S1 | ~S2, Instruction::LSL},   //
//     { N | ~E | ~L | ~F | ~A |  S | ~S1 |  S2, Instruction::LSR},   //
//     { N | ~E | ~L | ~F | ~A |  S |  S1 | ~S2, Instruction::ROT},   //
    { N | ~E | ~L | ~F |  A | ~S | ~S1 | ~S2, Instruction::MOV},
    { N | ~E | ~L |  F | ~A | ~S | ~S1 | ~S2, Instruction::FSUB},
    { N | ~E |  L | ~F | ~A | ~S | ~S1 | ~S2, Instruction::NOR},
    { N | ~E |  L | ~F |  A | ~S | ~S1 | ~S2, Instruction::NAND},
    { N |  E | ~L | ~F | ~A | ~S | ~S1 | ~S2, Instruction::DIV},
    { N |  E | ~L |  F | ~A | ~S | ~S1 | ~S2, Instruction::FDIV},
    { N |  E |  L | ~F | ~A | ~S | ~S1 | ~S2, Instruction::NXOR},
    { N |  E |  L | ~F |  A | ~S | ~S1 | ~S2, Instruction::NEG},
};

 */


/// Explicit template instantiation. It is done in order to keep template
/// implementation separately from its declaration
template class CPU<word>;
