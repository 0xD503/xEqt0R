#include "cpu.hpp"
#include "arch.hpp"


template<typename T>
CPU<T>::CPU(void) :
    _running(false), _registerFile()
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


/// Explicit template instantiation. It is done in order to keep template
/// implementation separately from its declaration
template class CPU<archBitDepth>;
