#ifndef __REGISTER_H__
#define __REGISTER_H__

#include <cstddef>


template<typename T>
class Register {
    public:
        explicit Register(T val);
        Register(void);
        ~Register(void);

    public:
        void write (const T val);
        void writeBit (const size_t index, bool val);
        const T& read (void) const;
        bool readBit (size_t index) const;

        T& operator+ (const T& addendum) {
            return (_value);
        }

    protected:
        T _value;

    private:
        //
};


#endif // __REGISTER_H__
