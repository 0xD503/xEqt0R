#ifndef __REGISTER_H__
#define __REGISTER_H__

#include "bit.hpp"
#include <cstddef>


template<typename T>
class Register {
    public:
        explicit Register(T val);
        Register(void);
        virtual ~Register(void) = default;

    public:
        // void write (T val);
        // void writeBit (size_t index, Bit_t val);
        T read (void) const;
        Bit_t readBit (size_t index) const;

    protected:
        T _value;

    private:
        //
};


#endif // __REGISTER_H__
