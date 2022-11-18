#include "cpu.hpp"

#include <cstddef>
#include <cstdint>

#include <bit>
#include <limits>


template<typename T, typename M, typename D>
CPU<T, M, D>::CPU(MemoryBus<T, M, D>& instrMemBus, MemoryBus<T, D, M>& dataMemBus) :
    Device(),
    _registerFile(),
    _flags(),
    _instrMemBus(instrMemBus), _dataMemBus(dataMemBus)
{
    //
}

template<typename T, typename M, typename D>
CPU<T, M, D>::~CPU() {
    //
}


template<typename T, typename M, typename D>
void CPU<T, M, D>::cycle (void) {
    //Device::run();

    EncodedInstruction encodedInstr = _fetch();
    Instruction decodedInstr = _decode(encodedInstr);
    _execute(decodedInstr, encodedInstr);
    //_writeBack(result);
    _incrementPC();
}

// template<typename T>
// void CPU<T, M, D>::stop (void) {
//     Device::stop();
// }


template<typename T, typename M, typename D>
EncodedInstruction CPU<T, M, D>::_fetch () const {
    EncodedInstruction encodedInstruction;

    /// Send signal throug memory bus to fetch instruction
    /// Design patter: ???
    /// TODO: increment PC during FETCH or EXECUTE???
    bool status = _instrMemBus.readMemory(__getCurrentPC().read(), encodedInstruction.data);
    if (status) {
        /// TODO: ???
    }
    else {
        /// TODO: ???
    }

    return (encodedInstruction);
}

template<typename T, typename M, typename D>
Instruction CPU<T, M, D>::_decode (EncodedInstruction encodedInstr) const {
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
            if (encodedInstr.memManipStd.load == 1) {
                if (encodedInstr.memManipStd.wide == 0) {
                    instruction = Instruction::LDR;
                }
                else {
                    instruction = Instruction::WLDR;
                }
            }
            else {
                if (encodedInstr.memManipStd.wide == 0) {
                    instruction = Instruction::STR;
                }
                else {
                    instruction = Instruction::WSTR;
                }
            }
            break;
        }
        case INSTR_TYPE::FLOW_CONT: {
            /// TODO:
            if (encodedInstr.flowCtrlStd.branch == 1) {
                BranchType br = static_cast<BranchType>(encodedInstr.flowCtrlStd.branchType);
                switch (br) {
                    case BranchType::ABSOLUTE: {
                        instruction = Instruction::B;
                        break;
                    }
                    case BranchType::RELATIVE: {
                        instruction = Instruction::BR;
                        break;
                    }
                    case BranchType::LINKED: {
                        instruction = Instruction::BLX;
                        break;
                    }

                    default: {
                        instruction = Instruction::FAULT;
                        break;
                    }
                }
            }
            else {
                /// TODO: other flow ctrl
            }
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

template<typename T, typename M, typename D>
void CPU<T, M, D>::_execute (Instruction instr, EncodedInstruction encodedInstr) {
    /// TODO: ADD flags changing on processing data
    switch (instr) {
        case Instruction::ADD: {
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
        case Instruction::MOV: {
            break;
        }
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
// void CPU<T, M, D>::_writeBack (word result)
// {
//     /// TODO: undone
// //    _registerFile[??] = _result;
// }



/// private section


template<typename T, typename M, typename D>
INSTR_TYPE CPU<T, M, D>::__decodeOpcode (EncodedInstruction encodedInstr) const {
    INSTR_TYPE type = INSTR_TYPE::UNKNOWN;

    switch (static_cast<CPU_MODE>(encodedInstr.headStd.mode.flag)) {
        case CPU_MODE::DEFAULT: {
            type = static_cast<INSTR_TYPE>(encodedInstr.headStd.opCode.code);
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
// void CPU<T, M, D>::__prepareDatapath (EncodedInstruction encodedInstr) {
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


template<typename T, typename M, typename D>
bool CPU<T, M, D>::__checkCondition (uint_fast8_t cond) const {
    bool allow = false;

    //

    return (true);
}

template<typename T, typename M, typename D>
void CPU<T, M, D>::__executeALUOp (EncodedInstruction encodedInstr, Instruction instr) {
    uint_fast8_t cond = static_cast<uint_fast8_t>(encodedInstr.headStd.cond.flags);
    if (__checkCondition(cond)) {
        word result;
        word operand_2;
        Registers targetRegID = static_cast<Registers>(encodedInstr.aluOpImmStd.targetReg);
        std::size_t srcReg_1_ID = encodedInstr.aluOpImmStd.srcReg_1;
        if (encodedInstr.aluOpStd.imm == 1) {
            operand_2 = encodedInstr.aluOpImmStd.immediate;
        }
        else {
            operand_2 = _registerFile[encodedInstr.aluOpRegStd.srcReg_2].read();
        }
        /// shift operand 2
        uint_fast8_t shamt = encodedInstr.dataProcStd.shamt;
        word operand_1 = _registerFile[srcReg_1_ID].read();
        operand_2 <<= shamt;
        switch (instr) {
            case Instruction::AND: {
                result = operand_1 & operand_2;
                break;
            }
            case Instruction::ORR: {
                result = operand_1 | operand_2;
                break;
            }
            case Instruction::XOR: {
                result = operand_1 ^ operand_2;
                break;
            }
            case Instruction::NAND: {
                result = ~(operand_1 & operand_2);
                break;
            }
            case Instruction::NOR: {
                result = ~(operand_1 | operand_2);
                break;
            }
            case Instruction::NXOR: {
                result = ~(operand_1 ^ operand_2);
                break;
            }
            case Instruction::ADD: {
                result = operand_1 + operand_2;
                break;
            }
            case Instruction::SUB: {
                result = operand_1 - operand_2;
                break;
            }
            case Instruction::MUL: {
                result = operand_1 * operand_2;
                break;
            }
            case Instruction::DIV: {
                if (operand_2 != 0) {
                    result = operand_1 / operand_2;
                    __writeBack(targetRegID, result);
                }
                else {
                    //result = UINT64_MAX;
                    /// TODO: report
                }
                break;
            }
            case Instruction::FADD: {
                result = static_cast<word>(static_cast<double>(operand_1) \
                         + static_cast<double>(operand_2));
                break;
            }
            case Instruction::FSUB: {
                result = static_cast<word>(static_cast<double>(operand_1) \
                         - static_cast<double>(operand_2));
                break;
            }
            case Instruction::FMUL: {
                result = static_cast<word>(static_cast<double>(operand_1) \
                         * static_cast<float>(operand_2));
                break;
            }
            case Instruction::FDIV: {
                if (operand_2 != 0) {
                    result = static_cast<word>(static_cast<float>(operand_1) \
                             / static_cast<float>(operand_2));
                    __writeBack(targetRegID, result);
                }
                else {
                    //result = std::numeric_limits<double>::max();
                }
                break;
            }
            case Instruction::MOV: {
                result = operand_2;
                break;
            }
            case Instruction::NEG: {
                result = ~operand_1;
                break;
            }
            /// Shift operations
            case Instruction::LSL: {
                result = operand_1 << shamt;
                break;
            }
            case Instruction::LSR: {
                result = operand_1 >> shamt;
                break;
            }
            case Instruction::ROT: {
                word regVal = operand_1;
                std::size_t num = arch::WORD_WIDE - shamt;
                word mask = (1UL << (num)) - 1;
                result = regVal >> shamt;
                result |= (regVal & mask) << (num);
                break;
            }
            case Instruction::ASR: {
                result = static_cast<word>(static_cast<sword>(operand_1) >> shamt);
                break;
            }
            case Instruction::MAX: {
                result = std::max(operand_1, operand_2);
                break;
            }
            case Instruction::MIN: {
                result = std::min(operand_1, operand_2);
                break;
            }
            case Instruction::POPCNT: {
#if __has_builtin(__builtin_popcount)
                result = static_cast<word>(std::popcount(operand_1));
#else
                result  = 0;
                while (operand_1 != 0) {
                    // if (operand_1 & 0x01) {
                    //     result++;
                    // }
                    result += operand_1 & 0x01;
                    operand_1 >>= 1;
                }
#endif  /// __has_builtin(__builtin_popcount)
                break;
            }

            default: {
                /// TODO:
                break;
            }
        }

        __writeBack(targetRegID, result);
    }
}

/// Memory manipulation instructions
template<typename T, typename M, typename D>
void CPU<T, M, D>::__executeMemOp (EncodedInstruction encodedInstr, Instruction instr) {
    size_t memAddr = _registerFile[encodedInstr.memManipStd.memAddr].read();
    Registers regAddr = static_cast<Registers>(encodedInstr.memManipStd.dataReg);
    D data;
    bool status;

    switch (instr) {
        case Instruction::LDR: {
            status = _dataMemBus.readMemory(memAddr, data);
            if (status) {
                __writeBack(regAddr, data);
            }
            else {
                /// TODO: report error
                /// 
            }
        //     __writeBack((Registers) encodedString.memoryManipStd.dataReg, data);
            break;
        }
        case Instruction::STR: {
            data = _registerFile.readRegister(regAddr);
            status = _dataMemBus.writeMemory(memAddr, data);
            if (status) {
                /// TODO:
            }
            else {
                /// TODO:
            }
            break;
        }
        case Instruction::WLDR: {
            /// TODO:
            break;
        }
        case Instruction::WSTR: {
            /// TODO:
            break;
        }

        default: {
            /// TODO:
            break;
        }
    }
}

template<typename T, typename M, typename D>
void CPU<T, M, D>::__executeFlowCtrlOp (EncodedInstruction encodedInstr, Instruction instr) {
    //

    switch (instr) {
        case Instruction::B: {
            /// TODO:
            break;
        }
        case Instruction::BR: {
            /// TODO:
            break;
        }
        case Instruction::BLX: {
            /// TODO:
            break;
        }
        case Instruction::NOP: {
            /// TODO:
            break;
        }

        default: {
            /// TODO:
            break;
        }
    }

            /// Flow control instructions
            // case Instruction::B: {
            //     //
            //     break;
            // }

            // case Instruction::NOP: {
            //     //
            //     break;
            // }
}


template<typename T, typename M, typename D>
void CPU<T, M, D>::__writeBack (Registers targetRegID, word result) {
    _registerFile.writeRegister(targetRegID, result);   /// write back
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
// const std::unordered_map<uint_fast8_t, Instruction> CPU<T, M, D>::__DPI_MappingTable = {
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

const std::unordered_map<uint_fast8_t, Instruction> CPU<T, M, D>::__DPI_MappingTable = {
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
template class CPU<word, word, word>;
