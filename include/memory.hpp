#ifndef MEMORY_H_
#define MEMORY_H_

#include <cstddef>
#include <vector>

#include "arch.hpp"


template<typename T>
class Memory {
    public:
        explicit Memory(size_t len);
        virtual ~Memory(void);


        inline size_t getCapacity (void) const    { return (_length); }

    protected:
        const size_t _length;    /// mem size in data words
        size_t _size;            /// mem size in bytes
        std::vector<T> _memory;

    private:
        //
};


#endif // MEMORY_H_
