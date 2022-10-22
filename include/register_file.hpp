#ifndef __REGISTER_FILE_HPP__
#define __REGISTER_FILE_HPP__

#include <array>

#include "register.hpp"


template<typename T>
class RegisterFile {
    public:
        explicit RegisterFile<T>(size_t len) :
            _length(len), _file(0) { }
        virtual ~RegisterFile(void) = default;

        void writeRegister (size_t reg, T val);
        void writeRegisterBit (size_t reg, size_t bitIndex, Bit_t val);
        T readRegister (size_t reg) const;
        T readRegisterBit (size_t reg, size_t bitIndex) const;

    protected:
        const size_t _length;
        std::array<Register<T>, _length> _file;

    private:
        //
};


#endif // __REGISTER_FILE_HPP__
