#include "cpu.hpp"
#include "arch.hpp"


template<typename T>
CPU<T>::CPU(void) :
    _running(false), _registerFile(REGISTERS::RegsNumber)
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
    _running = true;
}


template<typename T>
Instruction CPU<T>::_fetch (addr_t addr)
{
    //
}

template<typename T>
void CPU<T>::_decode (Instruction instr)
{
    //
}

template<typename T>
void CPU<T>::_execute (void)
{
    //
}

template<typename T>
void CPU<T>::_writeBack (void)
{
    //
}
