#ifndef __REGISTER_FILE_HPP__
#define __REGISTER_FILE_HPP__

#include <array>

#include "arch.hpp"
#include "bit.hpp"
#include "register.hpp"


template<typename T>
class RegisterFile {
    public:
        explicit RegisterFile(size_t len);
        virtual ~RegisterFile(void);

        void writeRegister (size_t reg, T val);
        void writeRegisterBit (size_t reg, size_t bitIndex, Bit_t val);
        T readRegister (size_t reg) const;
        T readRegisterBit (size_t reg, size_t bitIndex) const;

    protected:
        static constexpr size_t _length = REGISTERS::RegsNumber;
        std::array<Register<T>, _length> _file;

    private:
        //
};


#endif // __REGISTER_FILE_HPP__
