#include "cpu.hpp"
#include "arch.hpp"


CPU::CPU(void) :
    _running(false), _registerFile(REGISTERS::RegsNumber)
{
    //
}

CPU::~CPU(void)
{
    //
}


void CPU::run (void)
{
    running = true;
}

Instruction CPU::_fetch (addrt_t addr)
{
    //
}
