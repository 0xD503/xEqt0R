#ifndef __SETTINGS_H__
#define __SETTINGS_H__

#include <fstream>
#include <iostream>

#include <string>
#include <unistd.h>



using std::cout;
using std::cerr;
using std::endl;

class Settings {
    public:
        explicit Settings(int argc, char *argv[], \
                          std::ifstream& inF, std::ofstream& outF);
        ~Settings();

        inline bool isCorrect() const { return (__status); }

    private:
        bool __status;
        std::string __programName;
        std::ifstream& __instrMemInitFile;
        std::ofstream& __coreDumpFile;

    private:


        inline void __showUsage() {
            cout << __programName << " - usage:" << endl;
            cout << "    -i - instruction memory initialization file" << endl;
            cout << "    -o - data memory output file" << endl;
            cout << endl;
        }


        bool __handleOpts (int argc, char *argv[]);
};


#endif // __SETTINGS_H__
