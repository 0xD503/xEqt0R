#ifndef __REGISTER_H__
#define __REGISTER_H__

#include <cstddef>


template<typename T>
class Register {
    public:
        explicit Register(T val) :
            _value(val) { }
        Register(void) :
            _value() { };
        virtual ~Register(void) = default;

        void write (T val);
        void writeBit (size_t index, T val);
        T read (void) const;
        T readBit (size_t index) const;

    protected:
        T _value;

    private:
        //
};


#endif // __REGISTER_H__
