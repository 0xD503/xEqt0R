#include "register_file.hpp"


template<typename T>
RegisterFile<T>::RegisterFile(void) :
    _file()
{
    //
}

template<typename T>
RegisterFile<T>::~RegisterFile(void)
{
    //
}



template<typename T>
void RegisterFile<T>::writeRegister (size_t reg, T val)
{
    /// TODO: make reg index boundary check
    //static_assert(reg < _length, "regID >= regfile length");

    _file.at(reg).write(val);
}

template<typename T>
void RegisterFile<T>::writeRegisterBit (size_t reg, size_t bitIndex, Bit_t val)
{
    /// TODO: make reg and bit index boundary check
    // static_assert(reg < _length, "regID >= regfile length");
    // static_assert(bit < (sizeof(_file[0]) * 8), "bitID >= register size");

    _file.at(reg).writeBit(bitIndex, val);
}

template<typename T>
T RegisterFile<T>::readRegister (REGISTERS reg) const
{
    /// TODO: make reg index boundary check
    //static_assert(reg < _length, "reg index >= regfile length");

    return (_file.at(reg).read());
}

template<typename T>
Bit_t RegisterFile<T>::readRegisterBit (REGISTERS reg, size_t bitIndex) const
{
    /// TODO: make reg and bit index boundary check
    //static_assert(reg < _length, "reg index >= regfile length");
    //static_assert(bitIndex < (sizeof(_value) * 8), "bit index >= sizeof(_value)");

    //if (reg < _len)
    return (_file.at(reg).readBit(bitIndex));
}
