#ifndef MEMORY_H_
#define MEMORY_H_

//#include <stddef>
#include <array>


template<typename T>
class Memory {
    public:
        //getCap

    protected:
        size_t _capacity;
        std::array<T, _capacity> _memory;

    private:
        //
}


#endif // MEMORY_H_
