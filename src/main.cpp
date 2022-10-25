// #include "soc.hpp"





/// Draft



#include <cstddef>
#include <cstdint>
#include <iostream>
//#include "soc.hpp"
//#include "cpu.hpp"
//#include "instruction.hpp"
//#include "memory.hpp"
#include "arch.hpp"
#include "isa.hpp"
//#include "register.hpp"
//#include "register_file.hpp"


static constexpr size_t memLen = 2 << 8;


int main (int argc, char *argv[])
{
    //Instruction instr{0x01};
    //instr.getField();
    // SoC<archBitDepth, i_mem_addr_t> soc(memLen);
    // soc.run();
    // std::cout << "IMem cap: " << soc.getInstructionMemorySize() << "b, "
    //           << soc.getInstructionMemoryLength() << std::endl;
    //Register<archBitDepth> reg{0x03};
    //int b = fff();
    //reg.read();
    // RegisterFile<archBitDepth> regFile{};
    // regFile.writeRegister(REGISTERS::PC, 0x07);
    // std::cout << "PC now is " << regFile.readRegister(REGISTERS::PC);
    // Memory<i_mem_addr_t> mem{64};
    // std::cout << "Mem cap: " << mem.getSize() << "b, " << mem.getLength()
    //           << std::endl;
    // CPU<archBitDepth> cpu{};
    // cpu.run();

//    soc.run();



    uint64_t instrMemory[1 << 14] = {};  /// default initialize 2^16 bytes
    //uint64_t dataMemory[1 << 14] = {};  /// default initialize 2^16 bytes
    uint64_t pc = 0;
    uint64_t instr = 0;
    bool cpuRunning = false;

    /// init instr memory
    for (size_t i = 1; i < 777; i++)
    {
        if ((i % 8) == 0) {
            instrMemory[i - 1] = ISA::ADD;
            continue;
        }
        instrMemory[i - 1] = i % 8;
    }

    cpuRunning = true;
    while (cpuRunning) {
        instr = instrMemory[pc++];

        /// execute(instr);
        if (instr == 0)
            break;            /// Power off

        switch (instr) {
            case ISA::ADD: {
                std::cout << "ADDing something" << std::endl;
                break;
            }
            case ISA::SUB: {
                std::cout << "SUBstracting something" << std::endl;
                break;
            }
            case ISA::AND: {
                std::cout << "ANDing something" << std::endl;
                break;
            }
            case ISA::OR: {
                std::cout << "ORing something" << std::endl;
                break;
            }
            case ISA::B: {
                std::cout << "Branching somewhere" << std::endl;
                pc = pc + 2;
                break;
            }
            case ISA::MOV: {
                std::cout << "MOVing immediate to reg" << std::endl;
                break;
            }
            case ISA::LDR: {
                std::cout << "LoaDing something from mem to Reg" << std::endl;
                break;
            }
            case ISA::STR: {
                std::cout << "SToring something from Reg to mem" << std::endl;
                break;
            }

            default: {
                std::cout << "!!!!!!!!!!!!UNKNOWN INSTRUCTION!!!!!!!!!!!!!!" << std::endl;
                break;
            }
        }
    }

    std::cout << "Power off..." << std::endl;


    while (true)
    {
        //instr = readmem
        //execute(instr);
    }


    return (0);
}
