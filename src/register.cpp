#include "register.hpp"

#include "bit.hpp"


template<typename T>
Register<T>::Register(T val) :
    _value(val)
{
    //
}

template<typename T>
Register<T>::Register(void) :
    _value()
{
    //
}


// template<typename T>
// Register<T>::write (T val)
// {
//     _value = val;
// }

// template<typename T>
// Register<T>::writeBit (size_t bitIndex, Bit_t val)
// {
//     /// TODO: make bitIndex boundary check

//     if (val == Bit_t::LOGICAL_ONE) {
//         _value |= 1 << bitIndex;
//     }
//     else {
//         _value &= ~(1 << bitIndex);
//     }
// }

template<typename T>
T Register<T>::read (void) const
{
    return (_value);
}

template<typename T>
Bit_t Register<T>::readBit (size_t bitIndex) const
{
    /// TODO: make bitIndex boundary check

    Bit_t bit = Bit_t::LOGICAL_ZERO;
    if ((_value & (1 << bitIndex)) != 0)
    {
        bit = Bit_t::LOGICAL_ONE;
    };

    return (bit);
}
