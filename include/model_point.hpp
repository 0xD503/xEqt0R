#ifndef __MODEL_POINT_HPP__
#define __MODEL_POINT_HPP__

#include <mutex>


class ModelPoint {
    public:
        explicit ModelPoint(void) :
            _valid(false), _mtx()
        {
            //
        }
        virtual ~ModelPoint(void) = 0;

    protected:
        bool _valid;
        std::mutex _mtx;

    private:
        //
};


#endif // __MODEL_POINT_HPP__
