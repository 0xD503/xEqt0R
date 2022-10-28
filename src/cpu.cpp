#include "cpu.hpp"
#include <cstdint>


template<typename T>
CPU<T>::CPU(void) :
    _running(false),
    _encodedInstruction(), _instruction(INSTRUCTION::UNKNOWN), _result(),
    _registerFile()
{
    //
}

template<typename T>
CPU<T>::~CPU(void)
{
    //
}


template<typename T>
void CPU<T>::run (void)
{
    //_running = true;
}


template<typename T>
void CPU<T>::_fetch (void)
{
    /// Send signal throug memory bus to fetch instruction
    /// Design patter: ???
    /// TODO: increment PC during FETCH or EXECUTE???
    //_encodedInstruction.data = instrMemory[pc++];
}

template<typename T>
void CPU<T>::_decode (void)
{
    INSTR_TYPE type = __decodeOpcode();
    switch (type) {
        case INSTR_TYPE::DATA_PROC: {
            /// TODO:
            __prepareDatapath();
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



    //_instruction = ???
}

template<typename T>
void CPU<T>::_execute (void)
{
    /// TODO: ADD flags changing on processing data
    switch (_instruction) {
        case INSTRUCTION::ADD: {
            //std::cout << "ADDing something" << std::endl;
            uint_fast8_t cond = _encodedInstruction.field.condition;
            if (cond != 0)
            {
                /// TODO: break if condition doesn't allow to execute
            }
            //_result = _registerFile[??] + _registerFile[??];
            break;
        }
        // case INSTRUCTION::SUB: {
        //     //std::cout << "SUBstracting something" << std::endl;
        //     uint_fast8_t cond = _encodedInstruction.field.condition;
        //     _result = _registerFile[??] - _registerFile[??];
        //     break;
        // }
        // case INSTRUCTION::AND: {
        //     //std::cout << "ANDing something" << std::endl;
        //     _result = _registerFile[??] & _registerFile[??];
        //     break;
        // }
        // case INSTRUCTION::OR: {
        //     //std::cout << "ORing something" << std::endl;
        //     _result = _registerFile[??] | _registerFile[??];
        //     break;
        // }
        // case INSTRUCTION::B: {
        //     /// TODO: Undone
        //     //std::cout << "Branching somewhere" << std::endl;
        //     uint_fast8_t cond = _encodedInstruction.field.condition;
        //     //pc = pc + 2;
        //     break;
        // }
        // case INSTRUCTION::MOV: {
        //     /// TODO: Undone
        //     //std::cout << "MOVing immediate to reg" << std::endl;
        //     uint_fast8_t cond = _encodedInstruction.field.condition;
        //     _registerFile[??] = ??;
        //     break;
        // }
        // case INSTRUCTION::LDR: {
        //     /// TODO: Undone
        //     //std::cout << "LoaDing something from mem to Reg" << std::endl;
        //     _registerFile[??] = ??;
        //     break;
        // }
        // case INSTRUCTION::STR: {
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
}

template<typename T>
void CPU<T>::_writeBack (void)
{
    /// TODO: undone
//    _registerFile[??] = _result;
}



/// private section
template<typename T>
INSTR_TYPE CPU<T>::__decodeOpcode (void)
{
    switch ((CPU_MODE) _encodedInstruction.field.mode) {
        case CPU_MODE::DEFAULT: {
            INSTR_TYPE type = (INSTR_TYPE) _encodedInstruction.field.opCode;
            return (type);
            break;
        }
        case CPU_MODE::EXTENDED: {
            /// TODO: NOT SUPPORTED
            return (INSTR_TYPE::UNKNOWN);
            break;
        }

        default: {
            /// TODO: NOT SUPPORTED
            return (INSTR_TYPE::UNKNOWN);
            break;
        }
    }
}


template<typename T>
void CPU<T>::__prepareDatapath (void)
{
    /// TODO: check if its shift operation first
    //uint_fast8_t switches = _encodedInstruction.field.switches;
    //_instruction = __DPI_MappingTable.at(switches);


    // if (switches & ALU_SWITCHES::A) {
    //     if (switches & ALU_SWITCHES::E) {
    //         _instruction = INSTRUCTION::NEG;    /// binary negation
    //     }
    //     else {
    //         if (switches & ALU_SWITCHES::N) {
    //             _instruction = INSTRUCTION::NAND;
    //         }
    //         else {
    //             _instruction = INSTRUCTION::AND;
    //         }
    //     }
    // }
    // else {
    //     //
    // }
}


using namespace ALU_SWITCHES;

/// private data

/// Mapping table between Data Processing Instructions and their switches
template<typename T>
const std::unordered_map<uint_fast8_t, INSTRUCTION> CPU<T>::__DPI_MappingTable = {
    {~N | ~E | ~L | ~F | ~A, INSTRUCTION::ADD},
    {~N | ~E | ~L |  F | ~A, INSTRUCTION::FADD},
    {~N | ~E |  L | ~F | ~A, INSTRUCTION::ORR},
    {~N | ~E |  L | ~F |  A, INSTRUCTION::AND},
    {~N |  E | ~L | ~F | ~A, INSTRUCTION::MUL},
    {~N |  E | ~L |  F | ~A, INSTRUCTION::FMUL},
    {~N |  E |  L | ~F | ~A, INSTRUCTION::XOR},
    { N | ~E | ~L | ~F | ~A, INSTRUCTION::SUB},
    { N | ~E | ~L | ~F |  A, INSTRUCTION::MOV},
    { N | ~E | ~L |  F | ~A, INSTRUCTION::FSUB},
    { N | ~E |  L | ~F | ~A, INSTRUCTION::NOR},
    { N | ~E |  L | ~F |  A, INSTRUCTION::NAND},
    { N |  E | ~L | ~F | ~A, INSTRUCTION::DIV},
    { N |  E | ~L |  F | ~A, INSTRUCTION::FDIV},
    { N |  E |  L | ~F | ~A, INSTRUCTION::NXOR},
    { N |  E |  L | ~F |  A, INSTRUCTION::NEG},
};



/*
    {~N | ~E | ~L | ~F | ~A |  S | ~S1 |  S2, INSTRUCTION::ASR},   //
    { N | ~E | ~L | ~F | ~A |  S | ~S1 | ~S2, INSTRUCTION::LSL},   //
    { N | ~E | ~L | ~F | ~A |  S | ~S1 |  S2, INSTRUCTION::LSR},   //
    { N | ~E | ~L | ~F | ~A |  S |  S1 | ~S2, INSTRUCTION::ROT},   //

const std::unordered_map<uint_fast8_t, INSTRUCTION> CPU<T>::__DPI_MappingTable = {
    {~N | ~E | ~L | ~F | ~A | ~S | ~S1 | ~S2, INSTRUCTION::ADD},
    {~N | ~E | ~L | ~F | ~A |  S | ~S1 |  S2, INSTRUCTION::ASR},   //
    {~N | ~E | ~L |  F | ~A | ~S | ~S1 | ~S2, INSTRUCTION::FADD},
    {~N | ~E |  L | ~F | ~A | ~S | ~S1 | ~S2, INSTRUCTION::ORR},
    {~N | ~E |  L | ~F |  A | ~S | ~S1 | ~S2, INSTRUCTION::AND},
    {~N |  E | ~L | ~F | ~A | ~S | ~S1 | ~S2, INSTRUCTION::MUL},
    {~N |  E | ~L |  F | ~A | ~S | ~S1 | ~S2, INSTRUCTION::FMUL},
    {~N |  E |  L | ~F | ~A | ~S | ~S1 | ~S2, INSTRUCTION::XOR},
    { N | ~E | ~L | ~F | ~A | ~S | ~S1 | ~S2, INSTRUCTION::SUB},
    { N | ~E | ~L | ~F | ~A |  S | ~S1 | ~S2, INSTRUCTION::LSL},   //
    { N | ~E | ~L | ~F | ~A |  S | ~S1 |  S2, INSTRUCTION::LSR},   //
    { N | ~E | ~L | ~F | ~A |  S |  S1 | ~S2, INSTRUCTION::ROT},   //
    { N | ~E | ~L | ~F |  A | ~S | ~S1 | ~S2, INSTRUCTION::MOV},
    { N | ~E | ~L |  F | ~A | ~S | ~S1 | ~S2, INSTRUCTION::FSUB},
    { N | ~E |  L | ~F | ~A | ~S | ~S1 | ~S2, INSTRUCTION::NOR},
    { N | ~E |  L | ~F |  A | ~S | ~S1 | ~S2, INSTRUCTION::NAND},
    { N |  E | ~L | ~F | ~A | ~S | ~S1 | ~S2, INSTRUCTION::DIV},
    { N |  E | ~L |  F | ~A | ~S | ~S1 | ~S2, INSTRUCTION::FDIV},
    { N |  E |  L | ~F | ~A | ~S | ~S1 | ~S2, INSTRUCTION::NXOR},
    { N |  E |  L | ~F |  A | ~S | ~S1 | ~S2, INSTRUCTION::NEG},
};

 */


/// Explicit template instantiation. It is done in order to keep template
/// implementation separately from its declaration
template class CPU<word>;
