// #include "soc.hpp"





/// Draft



#include <cstddef>
#include <cstdint>
#include <iostream>

#include "soc.hpp"
//#include "cpu.hpp"
//#include "instruction.hpp"
//#include "memory.hpp"
//#include "arch.hpp"
//#include "isa.hpp"
//#include "register.hpp"
//#include "register_file.hpp"


static constexpr size_t memLen = 2 << 8;


int main (int argc, char *argv[])
{
    //Instruction instr{0x01};
    //instr.getField();
    // SoC<word, i_mem_addr_t> soc(memLen);
    // soc.run();
    // std::cout << "IMem cap: " << soc.getInstructionMemorySize() << "b, "
    //           << soc.getInstructionMemoryLength() << std::endl;
    //Register<word> reg{0x03};
    //int b = fff();
    //reg.read();
    // RegisterFile<word> regFile{};
    // regFile.writeRegister(Registers::PC, 0x07);
    // std::cout << "PC now is " << regFile.readRegister(Registers::PC);
    // Memory<i_mem_addr_t> mem{64};
    // std::cout << "Mem cap: " << mem.getSize() << "b, " << mem.getLength()
    //           << std::endl;
    // CPU<word> cpu{};
    // cpu.run();

//    soc.run();



    // uint64_t instrMemory[1 << 14] = {};  /// default initialize 2^16 bytes
    // //uint64_t dataMemory[1 << 14] = {};  /// default initialize 2^16 bytes
    // uint64_t pc = 0;
    // uint64_t instr = 0;
    // bool cpuRunning = false;

    // /// init instr memory
    // for (size_t i = 1; i < 777; i++)
    // {
    //     if ((i % 8) == 0) {
    //         instrMemory[i - 1] = INSTRUCTION::ADD;
    //         continue;
    //     }
    //     instrMemory[i - 1] = i % 8;
    // }

    // cpuRunning = true;
    // while (cpuRunning) {
    //     //

    //     //
    // }

    std::cout << "Power off..." << std::endl;


    while (true)
    {
        //instr = readmem
        //execute(instr);
    }


    return (0);
}
