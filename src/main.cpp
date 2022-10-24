#include "arch.hpp"
#include "soc.hpp"


static constexpr size_t memLen = 2 << 31;


int main (int argc, char *argv[])
{
    SoC<archBitDepth, addr_t> soc(memLen);

//    soc.run();


    while (true)
    {
        //instr = readmem
        //execute(instr);
    }


    return (0);
}
