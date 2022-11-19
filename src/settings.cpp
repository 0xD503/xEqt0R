#include "settings.hpp"


//
Settings::Settings(int argc, char *argv[], std::ifstream& inF, std::ofstream& outF) :
    __status(false), __programName(argv[0]),        \
    __instrMemInitFile(inF), __coreDumpFile(outF) {
    __programName = argv[0];
    __status = __handleOpts(argc, argv);
}

Settings::~Settings() {
    if (__instrMemInitFile.is_open()) {
        __instrMemInitFile.close();
    }
    if (__coreDumpFile.is_open()) {
        __coreDumpFile.close();
    }
}


bool Settings::__handleOpts (int argc, char *argv[]) {
    bool status = false;
    int opt;

    opterr = 0;      /// clear error flag
    if (argc > 1) {
        while ((opt = getopt(argc, argv, "io")) != -1) {
            switch (opt) {
                case 'i': { /// instruction memory init file
                    __instrMemInitFile.open(optarg);
                    if (!__instrMemInitFile.is_open()) {
                        cout << "Failed to open input file" << endl;
                    }
                    break;
                }
                case 'o': { /// output core file
                    __coreDumpFile.open(optarg);
                    if (!__coreDumpFile.is_open()) {
                        cout << "Failed to open output file" << endl;
                    }
                    break;
                }
                case ':': { /// missing important option
                    cout << "Missing argument: " << static_cast<char>(optopt) \
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
