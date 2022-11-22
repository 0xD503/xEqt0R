#include "settings.hpp"

#include <fstream>
#include <unistd.h>
#include <sys/stat.h>


using std::cout;
using std::endl;

template<typename IT>
Settings<IT>::Settings(int argc, char *argv[], Memory<IT>& instrMem) :
    __programName(argv[0]), __executableFileName(), __coreFileName("xeqt.dump"),
    __instrMemInitFile(), __coreDumpFile(),
    __instrMemory(instrMem),
    __status(__handleOpts(argc, argv)) {
    configure();
}

template<typename IT>
Settings<IT>::~Settings() {
    if (__instrMemInitFile.is_open()) {
        __instrMemInitFile.close();
    }
    if (__coreDumpFile.is_open()) {
        __coreDumpFile.close();
    }
}


template<typename IT>
bool Settings<IT>::copyBin2Buff (std::ifstream& binF, std::string fName,
                                 Memory<IT>& mem) {
    bool status(false);
    std::streampos fileLen;

    binF.open(fName, std::ios::binary | std::ios::ate);
    if (binF.is_open()) {
        fileLen = binF.tellg();    /// Check file size
        if ((fileLen != - 1) && (fileLen <= mem.getSize())) {
            binF.seekg(0);                      /// go to the file beginning
            //binF.read();
        }
        else {
            cout << "Failed to init instruction memory" << endl;
        }

        status = true;
    }

    return (status);
}

template<typename IT>
bool Settings<IT>::configure() {
    bool status(false);

    //__instrMemInitFile.open(__executableFileName);

    //if (__instrMemInitFile.is_open() && __coreDumpFile.is_open()) {
    status = copyBin2Buff(__instrMemInitFile, __executableFileName,
                          __instrMemory);

    return (status);
}


template<typename IT>
bool Settings<IT>::__handleOpts (int argc, char *argv[]) {
    bool status = false;
    int opt;

    opterr = 0;      /// clear error flag
    if (argc > 1) {
        while ((opt = getopt(argc, argv, "i:o:")) != -1) {
            switch (opt) {
                case 'i': { /// instruction memory init file
                    /// Check if a given file exists
                    struct stat statBuf;
                    int exists = stat(optarg, &statBuf);
                    if (exists != 0) {
                        cout << "Failed to find file: " // << optarg
                             << endl;
                        goto end;
                    }
                    __executableFileName = optarg;
                    break;
                }
                case 'o': { /// output core file
                    /// set core file name
                    __coreFileName = optarg;
                    break;
                }
                case ':': { /// missing important option
                    cout << "Missing argument for: " << static_cast<char>(optopt) \
                         << endl;
                    cout << endl;
                    __showUsage();
                    goto end;
                    break;
                }
                case '?': { /// unknown option detected
                    cout << "Unknow option detected, ignoring it: " \
                         << static_cast<char>(optopt) << endl;
                    break;
                }

                default: {
                    __showUsage();
                    break;
                }
            }
        }
    }

    status = true;

end:
    return (status);
}


/// Explicit template instantiation. It is done in order to keep template
/// implementation separately from its declaration
template class Settings<word>;
