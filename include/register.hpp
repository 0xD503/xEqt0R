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

        /// prefix increment
        Register& operator++() {
            return (*this);
        }
        /// postfix increment
        Register operator++(int) {
            Register<T> old = *this;  /// copy old val
            operator++();             /// prefix
            return (old);             /// return old val
        }
        // T operator+ (const T& addendum) {
        //     return (_value);
        // }

    protected:
        T _value;

    private:
        //
};


#endif // __REGISTER_H__
