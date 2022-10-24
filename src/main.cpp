//#include "arch.hpp"
// #include "soc.hpp"
// #include "soc.hpp"
// #include "soc.hpp"
// #include "soc.hpp"
//#include "memory.hpp"
#include "register.hpp"


//static constexpr size_t memLen = 2 << 8;


int main (int argc, char *argv[])
{
    //SoC<archBitDepth, addr_t> soc(memLen);
    Register<int> reg;
    reg.read();
    //Memory<int> mem{64};

//    soc.run();


    while (true)
    {
        //instr = readmem
        //execute(instr);
    }


    return (0);
}
