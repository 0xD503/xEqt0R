#include "cpu.hpp"

#include <cstdint>

#include <limits>


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
    _execute(decodedInstr, encodedInstr);
    // _writeBack(result);
}

// template<typename T>
// void CPU<T>::stop (void) {
//     Device::stop();
// }


template<typename T>
EncodedInstruction CPU<T>::_fetch (void) const {
    EncodedInstruction encodedInstruction;

    /// Send signal throug memory bus to fetch instruction
    /// Design patter: ???
    /// TODO: increment PC during FETCH or EXECUTE???
    //_encodedInstruction.data = instrMemory[pc];
    //_encodedInstruction.data = instrMemory[pc++];

    return (encodedInstruction);
}

template<typename T>
Instruction CPU<T>::_decode (EncodedInstruction encodedInstr) const {
    Instruction instruction;
    INSTR_TYPE type = __decodeOpcode(encodedInstr);

    switch (type) {
        case INSTR_TYPE::DATA_PROC: {
            /// TODO:
            /// Check op code
            if (encodedInstr.dataProcStd.shift == 1) {    /// shift type op
                ShiftType shtType = static_cast<ShiftType>(encodedInstr.shiftOpStd.shiftType);

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
                        instruction = Instruction::UNKNOWN;
                        //static_assert(false, "wrong shift type");
                        break;
                    }
                }
            }
            else {                                      /// ALU operation
                uint_fast8_t extension = encodedInstr.aluOpStd.switches.flags.extended;
                // instruction = __DPI_MappingTable.at(switches);
                if (encodedInstr.aluOpStd.switches.flags.negate == 1) {
                    /// Operations with negation
                    if (encodedInstr.aluOpStd.switches.flags.logical == 1) {
                        /// Logical operations with negation
                        if (encodedInstr.aluOpStd.switches.flags.floating == 0) {
                            /// Logical operations with negation
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
                            /// no logical operations with real numbers
                            instruction = Instruction::UNKNOWN;
                        }
                    }
                    else {
                        /// Arithmetical operations with negation
                        if (encodedInstr.aluOpStd.switches.flags.floating == 1) {
                            /// Real numbers arithmethic with negation
                            switch (extension) {
                                case 0b00: {
                                    instruction = Instruction::FSUB;
                                    break;
                                }
                                case 0b10: {
                                    instruction = Instruction::FDIV;
                                    break;
                                }

                                default: {
                                    instruction = Instruction::UNKNOWN;
                                    break;
                                }
                            }
                        }
                        else {
                            /// Integer numbers arithmethic with negation
                            switch (extension) {
                                case 0b00: {
                                    instruction = Instruction::SUB;
                                    break;
                                }
                                case 0b01: {
                                    instruction = Instruction::MOV;
                                    break;
                                }
                                case 0b10: {
                                    instruction = Instruction::DIV;
                                    break;
                                }

                                default: {
                                    instruction = Instruction::UNKNOWN;
                                    break;
                                }
                            }
                        }
                    }
                }
                else {
                    /// Operations without negation
                    if (encodedInstr.aluOpStd.switches.flags.logical == 1) {
                        /// Logical operations without negation
                        if (encodedInstr.aluOpStd.switches.flags.floating == 0) {
                            /// Logical operations on integers without negation
                            switch (extension) {
                                case 0b00: {
                                    instruction = Instruction::ORR;
                                    break;
                                }
                                case 0b01: {
                                    instruction = Instruction::AND;
                                    break;
                                }
                                case 0b10: {
                                    instruction = Instruction::XOR;
                                    break;
                                }

                                default: {
                                    instruction = Instruction::UNKNOWN;
                                    break;
                                }
                            }
                        }
                        else {
                            /// No logical operations with real numbers
                            instruction = Instruction::UNKNOWN;
                        }
                    }
                    else {
                        /// Arithmetical operations without negation
                        if (encodedInstr.aluOpStd.switches.flags.floating == 1) {
                            /// Arithmetical operations on real numbers without negation
                            switch (extension) {
                                case 0b00: {
                                    instruction = Instruction::FADD;
                                    break;
                                }
                                case 0b10: {
                                    instruction = Instruction::FMUL;
                                    break;
                                }

                                default: {
                                    instruction = Instruction::UNKNOWN;
                                    break;
                                }
                            }
                        }
                        else {
                            /// Arithmetical operations on integers without negation
                            switch (extension) {
                                case 0b00: {
                                    instruction = Instruction::ADD;
                                    break;
                                }
                                case 0b10: {
                                    instruction = Instruction::MUL;
                                    break;
                                }

                                default: {
                                    instruction = Instruction::UNKNOWN;
                                    break;
                                }
                            }
                        }
                    }
                }
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
void CPU<T>::_execute (Instruction instr, EncodedInstruction encodedInstr) {
    /// TODO: ADD flags changing on processing data
    switch (instr) {
        case Instruction::ADD: {
            // uint_fast8_t cond = static_cast<uint_fast8_t>(encodedInstr.headStd.cond.flags);
            // if (__checkCondition(cond)) {
            //     Registers targetRegID = (Registers) encodedInstr.aluOpImmStd.targetReg;
            //     std::size_t srcReg_1_ID = encodedInstr.aluOpImmStd.srcReg_1;
            //     if (encodedInstr.aluOpStd.imm == 1) {
            //         operand_2 = encodedInstr.aluOpImmStd.immediate;
            //     }
            //     else {
            //         operand_2 = _registerFile[encodedInstr.aluOpRegStd.srcReg_2].read();
            //     }
            //     result = _registerFile[srcReg_1_ID].read() + operand_2;
            //     _registerFile.writeRegister(targetRegID, result);
            // }
            break;
        }
        case Instruction::SUB: {
            //
            break;
        }
        case Instruction::AND: {
            //
            break;
        }
        case Instruction::ORR: {
            //
            break;
        }
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
        // case Instruction::B:Instruction {
        //     /// TODO: Undone
        //     //std::cout << "Branching somewhere" << std::endl;
        //     uint_fast8_t cond = _encodedInstruction.field.condition;
        //     //pc = pc + 2;
        //     break;
        // }

        default: {
            /// TODO: Undone wrong instruction handling
            //std::cout << "!!!!!!!!!!!!UNKNOWN INSTRUCTION!!!!!!!!!!!!!!" << std::endl;
            break;
        }
    }

//    return (result);
}

// template<typename T>
// void CPU<T>::_writeBack (word result)
// {
//     /// TODO: undone
// //    _registerFile[??] = _result;
// }



/// private section
template<typename T>
INSTR_TYPE CPU<T>::__decodeOpcode (EncodedInstruction encodedInstr) const {
    INSTR_TYPE type = INSTR_TYPE::UNKNOWN;

    switch ((CPU_MODE) encodedInstr.headStd.mode.flag) {
        case CPU_MODE::DEFAULT: {
            type = (INSTR_TYPE) encodedInstr.headStd.opCode.code;
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

// template<typename T>
// void CPU<T>::__prepareDatapath (EncodedInstruction encodedInstr) {
//     /// TODO: check if its shift operation first
//     //DataProcTypeHeadStd dataProcType =
//     //_encodedInstruction
//     //uint_fast8_t sw = _encodedInstruction.field.sw;
//     //_instruction = __DPI_MappingTable.at(sw);


//     // if (sw & ALU_SW::A) {
//     //     if (switches & ALU_SWITCHES::E) {
//     //         _instruction = Instruction::NEG;    /// binary negation
//     //     }
//     //     else {
//     //         if (switches & ALU_SWITCHES::N) {
//     //             _instruction = Instruction::NAND;
//     //         }
//     //         else {
//     //             _instruction = Instruction::AND;
//     //         }
//     //     }
//     // }
//     // else {
//     //     //
//     // }
// }


template<typename T>
bool CPU<T>::__checkCondition (uint_fast8_t cond) const {
    bool allow = false;

    //

    return (allow);
}

template<typename T>
void CPU<T>::__executeALUOp (EncodedInstruction encodedInstr, Instruction instr) {
    word result;
    word operand_2;

    uint_fast8_t cond = static_cast<uint_fast8_t>(encodedInstr.headStd.cond.flags);
    if (__checkCondition(cond)) {
        Registers targetRegID = (Registers) encodedInstr.aluOpImmStd.targetReg;
        std::size_t srcReg_1_ID = encodedInstr.aluOpImmStd.srcReg_1;
        if (encodedInstr.aluOpStd.imm == 1) {
            operand_2 = encodedInstr.aluOpImmStd.immediate;
        }
        else {
            operand_2 = _registerFile[encodedInstr.aluOpRegStd.srcReg_2].read();
        }
        switch (instr) {
            case Instruction::AND: {
                result = _registerFile[srcReg_1_ID].read() & operand_2;
                break;
            }
            case Instruction::ORR: {
                result = _registerFile[srcReg_1_ID].read() | operand_2;
                break;
            }
            case Instruction::XOR: {
                result = _registerFile[srcReg_1_ID].read() ^ operand_2;
                break;
            }
            case Instruction::NAND: {
                result = ~(_registerFile[srcReg_1_ID].read() & operand_2);
                break;
            }
            case Instruction::NOR: {
                result = ~(_registerFile[srcReg_1_ID].read() | operand_2);
                break;
            }
            case Instruction::NXOR: {
                result = ~(_registerFile[srcReg_1_ID].read() ^ operand_2);
                break;
            }
            case Instruction::ADD: {
                result = _registerFile[srcReg_1_ID].read() + operand_2;
                break;
            }
            case Instruction::SUB: {
                result = _registerFile[srcReg_1_ID].read() - operand_2;
                break;
            }
            case Instruction::MUL: {
                result = _registerFile[srcReg_1_ID].read() * operand_2;
                break;
            }
            case Instruction::DIV: {
                if (operand_2 != 0) {
                    result = _registerFile[srcReg_1_ID].read() / operand_2;
                }
                else {
                    result = UINT64_MAX;
                }
                break;
            }
            // case Instruction::FADD: {
            //     result = _registerFile[srcReg_1_ID].read() + operand_2;
            //     break;
            // }
            // case Instruction::FSUB: {
            //     result = _registerFile[srcReg_1_ID].read() - operand_2;
            //     break;
            // }
            // case Instruction::FMUL: {
            //     result = static_cast<float>(_registerFile[srcReg_1_ID].read() * operand_2);
            //     break;
            // }
            // case Instruction::FDIV: {
            //     if (operand_2 != 0) {
            //         result = static_cast<float>(_registerFile[srcReg_1_ID].read() / operand_2);
            //     }
            //     else {
            //         result = std::numeric_limits<double>::max();
            //     }
            //     break;
            // }

            // case MOV: {
            //     break;
            // }
            // case NEG: {
            //     break;
            // }
        }
        _registerFile.writeRegister(targetRegID, result);
    }
}


/// private data

////     {~N | ~E | ~L | ~F | ~A, Instruction::ADD},
////     {~N | ~E | ~L |  F | ~A, Instruction::FADD},
////     {~N | ~E |  L | ~F | ~A, Instruction::ORR},
//////     {~N | ~E |  L | ~F |  A, Instruction::AND},
/////     {~N |  E | ~L | ~F | ~A, Instruction::MUL},
/////     {~N |  E | ~L |  F | ~A, Instruction::FMUL},
/////     {~N |  E |  L | ~F | ~A, Instruction::XOR},
////     { N | ~E | ~L | ~F | ~A, Instruction::SUB},
//////     { N | ~E | ~L | ~F |  A, Instruction::MOV},
////     { N | ~E | ~L |  F | ~A, Instruction::FSUB},
////     { N | ~E |  L | ~F | ~A, Instruction::NOR},
//////     { N | ~E |  L | ~F |  A, Instruction::NAND},
/////     { N |  E | ~L | ~F | ~A, Instruction::DIV},
/////     { N |  E | ~L |  F | ~A, Instruction::FDIV},
/////     { N |  E |  L | ~F | ~A, Instruction::NXOR},
///////     { N |  E |  L | ~F |  A, Instruction::NEG},
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
