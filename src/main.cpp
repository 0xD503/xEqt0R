//#include <cstdlib>

#include "settings.hpp"
#include "soc.hpp"



int main (int argc, char *argv[])
{
    int status = EXIT_FAILURE;
    std::ifstream instrMemInitFile;
    std::ofstream coreDumpFile;

    /// set up before starting
    Settings settings(argc, argv, instrMemInitFile, coreDumpFile);
    SoC<word, word, word> soc(32768, 32768);
    if (!settings.isCorrect()) {
        goto end;
    }
    // Memory<word> memory(32768);

    // //word temp = 0xDEADFEED;
    // word temp = 15;
    // bool status = memory.writeWord(2, temp);
    // temp = 7;
    // status = memory.writeWord(3, temp);

    // status = memory.readWord(2, temp);
    // std::cout << "First word: " << temp << std::endl;
    // status = memory.readWord(3, temp);
    // std::cout << "Second word: " << temp << std::endl;

    soc.run();

    //std::cout << "Power off..." << std::endl;

    status = EXIT_SUCCESS;


end:
    return (status);
}
