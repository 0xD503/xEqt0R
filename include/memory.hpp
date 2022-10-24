#ifndef MEMORY_H_
#define MEMORY_H_

#include <cstddef>
#include <vector>

#include "arch.hpp"


template<typename T>
class Memory {
    public:
        explicit Memory<T>(size_t len);
        virtual ~Memory(void);


        inline size_t getCap (void) const    { return (_capacity); }

    protected:
        const size_t _length;    /// size in data words
        size_t _capacity;                   /// mem size in bytes
        std::vector<T> _memory;

    private:
        //
};


#endif // MEMORY_H_
