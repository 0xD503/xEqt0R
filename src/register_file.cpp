#include "register_file.hpp"


RegisterFile::RegisterFile(size_t len) :
    _length(len), _file()
{
    //
}

RegisterFile::~RegisterFile(void)
{
    //
}



template<typename T>
RegisterFile::writeRegister (size_t reg, T val)
{
    static_assert(reg < _length, "regID >= regfile length");

    _file.at(reg).write(val);
}

RegisterFile::writeRegisterBit (size_t reg, size_t bitIndex, Bit_t val)
{
    static_assert(reg < _length, "regID >= regfile length");
    static_assert(bit < (sizeof(_file[0]) * 8), "bitID >= register size");

    _file.at(reg).writeBit(bitIndex, val);
}

template<typename T>
T RegisterFile::readRegister (size_t reg) const
{
    static_assert(reg < _length, "reg index >= regfile length");

    return (_file.at(reg).read());
}

Bit_t Register::readRegisterBit (size_t reg, size_t bitIndex) const
{
    static_assert(reg < _length, "reg index >= regfile length");
    static_assert(bitIndex < (sizeof(_value) * 8), "bit index >= sizeof(_value)");

    //if (reg < _len)
    return (_file.at(reg).readBit(bitIndex));
}
