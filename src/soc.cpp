#include "soc.hpp"


template<typename T, typename M, typename D>
SoC<T, M, D>::SoC(size_t instrMemLen, size_t dataMemLen,
                  int argc, char *argv[]) :
    __failed(true),
    __cpu(__instrMemoryBus, __dataMemoryBus),
    __instructionMemory(instrMemLen), __dataMemory(dataMemLen),
    __instrMemoryBus(__cpu, __instructionMemory),
    __dataMemoryBus(__cpu, __dataMemory),
    __settings(argc, argv, __instructionMemory)
{
    if (__settings.isCorrect()) {
        __failed = false;
        //__settings.
    }
}

template<typename T, typename M, typename D>
SoC<T, M, D>::~SoC(void)
{
    //
}


template<typename T, typename M, typename D>
int SoC<T, M, D>::run (void)
{
    int status = -1;

    if (isFailed()) {
        goto end;
    }

    //

    status = 0;

end:
    return (status);
}


/// Explicit template instantiation. It is done in order to keep template
/// implementation separately from its declaration
template class SoC<word, word, word>;
