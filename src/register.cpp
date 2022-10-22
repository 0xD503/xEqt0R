#include "register.hpp"

#include "bit.hpp"


template<typename T>
Register::write (T val)
{
    _value = val;
}

Register::writeBit (size_t bitIndex, Bit_t val)
{
    static_assert(bitIndex < (sizeof(_value) * 8), "bit index >= sizeof(_value)");
    //if (bitIndex < (sizeof(_value) * 8))
    //{
        if (val == Bit_t::LOGICAL_ONE) {
            _value |= 1 << bitIndex;
        }
        else {
            _value &= ~(1 << bitIndex);
        }
    //}
}

template<typename T>
T Register::read (void) const
{
    return (_value);
}

Bit_t Register::readBit (size_t bitIndex) const
{
    static_assert(bitIndex < (sizeof(_value) * 8), "bit index >= sizeof(_value)");

    Bit_t bit = Bit_t::LOGICAL_ZERO;
    //if (bitIndex < (sizeof(_value) * 8))
    //{
        if ((_value & (1 << bitIndex)) != 0)
        {
            bit = Bit_t::LOGICAL_ONE;
        };
    //}

    return (bit);
}
