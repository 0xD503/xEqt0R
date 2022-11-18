#include <cstddef>
#include <cstdint>
#include <iostream>

//#include "arch.hpp"
#include "memory.hpp"
#include "soc.hpp"


static constexpr size_t memLen = 2 << 8;


int main (int argc, char *argv[])
{
    SoC<word, word, word> soc(32768, 32768);
    // Memory<word> memory(32768);

    // //word temp = 0xDEADFEED;
    // word temp = 15;
    // bool status = memory.writeWord(2, temp);
    // temp = 7;
    // status = memory.writeWord(3, temp);

    // status = memory.readWord(2, temp);
    // std::cout << "First word: " << temp << std::endl;
    // status = memory.readWord(3, temp);
    // std::cout << "Second word: " << temp << std::endl;

    soc.run();

    std::cout << "Power off..." << std::endl;


    while (true)
    {
        //instr = readmem
        //execute(instr);
    }


    return (0);
}
