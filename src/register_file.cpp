#include "register_file.hpp"


template<typename T>
RegisterFile<T>::RegisterFile(void) :
    _file() {
    //
}

template<typename T>
RegisterFile<T>::~RegisterFile(void)
{
    //
}



template<typename T>
void RegisterFile<T>::writeRegister (Registers reg, T val)
{
    /// TODO: make reg index boundary check
    //static_assert(reg < _length, "regID >= regfile length");

    _file.at((size_t) reg).write(val);
}

template<typename T>
void RegisterFile<T>::writeRegisterBit (Registers reg, size_t bitIndex, bool val)
{
    /// TODO: make reg and bit index boundary check
    // static_assert(reg < _length, "regID >= regfile length");
    // static_assert(bit < (sizeof(_file[0]) * 8), "bitID >= register size");

    _file.at((size_t) reg).writeBit(bitIndex, val);
}

template<typename T>
T RegisterFile<T>::readRegister (Registers reg) const
{
    /// TODO: make reg index boundary check
    //static_assert(reg < _length, "reg index >= regfile length");

    return (_file.at((size_t) reg).read());
}

template<typename T>
bool RegisterFile<T>::readRegisterBit (Registers reg, size_t bitIndex) const
{
    /// TODO: make reg and bit index boundary check
    //static_assert(reg < _length, "reg index >= regfile length");
    //static_assert(bitIndex < (sizeof(_value) * 8), "bit index >= sizeof(_value)");

    //if (reg < _len)
    return (_file.at((size_t) reg).readBit(bitIndex));
}


/// Explicit template instantiation. It is done in order to keep template
/// implementation separately from its declaration
template class RegisterFile<word>;
