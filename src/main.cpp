// #include "soc.hpp"






#include <iostream>
#include "soc.hpp"
//#include "cpu.hpp"
//#include "instruction.hpp"
//#include "memory.hpp"
#include "arch.hpp"
//#include "register.hpp"
//#include "register_file.hpp"


static constexpr size_t memLen = 2 << 8;


int main (int argc, char *argv[])
{
    //Instruction instr{0x01};
    //instr.getField();
    SoC<archBitDepth, i_mem_addr_t> soc(memLen);
    soc.run();
    std::cout << "IMem cap: " << soc.getInstructionMemorySize() << "b, "
              << soc.getInstructionMemoryLength() << std::endl;
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


    while (true)
    {
        //instr = readmem
        //execute(instr);
    }


    return (0);
}
