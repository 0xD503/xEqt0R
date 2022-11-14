#ifndef __REGISTER_FILE_HPP__
#define __REGISTER_FILE_HPP__

#include <array>
#include <cstddef>

#include "arch.hpp"
#include "register.hpp"


template<typename T>
class RegisterFile {
    public:
        explicit RegisterFile(void);
        ~RegisterFile(void);

    public:
        void writeRegister (Registers reg, T val);
        void writeRegisterBit (Registers reg, size_t bitIndex, bool val);
        T readRegister (Registers reg) const;
        bool readRegisterBit (Registers reg, size_t bitIndex) const;

        inline const Register<T>& operator[] (const std::size_t reg) const {
            return (_file[reg]);
        }
        Register<T>& operator[] (const std::size_t reg) {
            return (_file[reg]);
        }

    protected:
        static constexpr std::size_t _length = static_cast<std::size_t>(1 << arch::REGISTERS_POWER);
        std::array<Register<T>, _length> _file;

    private:
        //
};


#endif // __REGISTER_FILE_HPP__
