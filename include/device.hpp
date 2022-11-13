#ifndef __DEVICE_H__
#define __DEVICE_H__

//


class Device {
    public:
        Device() : _running(false) { }
        virtual ~Device() = 0;

        inline virtual void run (void) {
            _running = true;
        }
        inline virtual void stop (void) {
            _running = false;
        }

    protected:
        bool _running;
};


#endif // __DEVICE_H__
