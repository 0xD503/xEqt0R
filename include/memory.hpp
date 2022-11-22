#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <cstddef>
#include <vector>

#include "arch.hpp"


template<typename T>
class Memory {
    public:
        explicit Memory(size_t len);
        virtual ~Memory(void);


        inline size_t getLength (void) const    { return (_length); }
        inline size_t getSize (void) const      { return (_size); }
        inline const T *getRawPtr (void) const        { return (_memory.data()); }

        /// return false if failed to read
        inline bool readWord (const size_t addr, T &dest) const {
            bool status = false;

            if (addr < getLength()) {
                dest  = _memory[addr];
                status = true;
            }

            return (status);
        }
        /// return false if failed to write
        inline bool writeWord (const size_t addr, const T &src) {
            bool status = false;

            if (addr < getLength()) {
                _memory[addr] = src;
                status = true;
            }

            return (status);
        }

    protected:
        const size_t _length;    /// mem size in data words
        const size_t _size;      /// mem size in bytes
        std::vector<T> _memory;

    private:
        //
};


#endif // __MEMORY_H__
