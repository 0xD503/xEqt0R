#ifndef __SETTINGS_H__
#define __SETTINGS_H__

#include <fstream>
#include <iostream>

#include <string>

#include "memory.hpp"



template<typename IT>
class Settings {
    public:
        explicit Settings(int argc, char *argv[], Memory<IT>& instrMem);
        ~Settings();

        inline bool isCorrect() const { return (__status); }

        bool copyBin2Buff (std::ifstream& binF, std::string fName,
                           Memory<IT>& buff);
        bool configure ();

    private:
        std::string __programName;
        std::string __executableFileName, __coreFileName;
        std::ifstream __instrMemInitFile;
        std::ofstream __coreDumpFile;
        Memory<IT>& __instrMemory;
        bool __status;

    private:
        inline void __showUsage() {
            std::cout << __programName << " - usage:" << std::endl;
            std::cout << "    -i - instruction memory initialization file" << std::endl;
            std::cout << "    -o - data memory output file" << std::endl;
            std::cout << std::endl;
        }

        bool __handleOpts (int argc, char *argv[]);
};


#endif // __SETTINGS_H__
