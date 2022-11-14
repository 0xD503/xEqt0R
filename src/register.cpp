#include "register.hpp"

#include "arch.hpp"


template<typename T>
Register<T>::Register(T val) :
    _value(val)
{
    //
}

template<typename T>
Register<T>::Register(void) :
    _value() {
    //
}

template<typename T>
Register<T>::~Register(void) {
    //
}


template<typename T>
void Register<T>::write (const T val) {
    _value = val;
}

template<typename T>
void Register<T>::writeBit (const size_t bitIndex, bool val) {
    /// TODO: make bitIndex boundary check

    if (val) {
        _value |= 1 << bitIndex;
    }
    else {
        _value &= ~(1 << bitIndex);
    }
}

template<typename T>
const T& Register<T>::read (void) const
{
    return (_value);
}

template<typename T>
bool Register<T>::readBit (size_t bitIndex) const
{
    /// TODO: make bitIndex boundary check

    bool bit = ((_value & (1 << bitIndex)) != 0) ?  true : false;
    // Bit_t bit = Bit_t::LOGICAL_ZERO;
    // if ((_value & (1 << bitIndex)) != 0)
    // {
    //     bit = Bit_t::LOGICAL_ONE;
    // };

    return (bit);
}


/// Explicit template instantiation. It is done in order to keep template
/// implementation separately from its declaration
template class Register<word>;
