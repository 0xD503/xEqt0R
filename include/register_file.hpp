#ifndef __REGISTER_FILE_HPP__
#define __REGISTER_FILE_HPP__

#include <array>
#include <cstddef>

#include "arch.hpp"
#include "bit.hpp"
#include "register.hpp"


template<typename T>
class RegisterFile {
    public:
        explicit RegisterFile(void);
        ~RegisterFile(void);

    public:
        void writeRegister (REGISTERS reg, T val);
        void writeRegisterBit (REGISTERS reg, size_t bitIndex, Bit_t val);
        T readRegister (REGISTERS reg) const;
        Bit_t readRegisterBit (REGISTERS reg, size_t bitIndex) const;

    protected:
        static constexpr size_t _length = (const size_t) REGISTERS::RegsNumber;
        std::array<Register<T>, _length> _file;

    private:
        //
};


#endif // __REGISTER_FILE_HPP__
