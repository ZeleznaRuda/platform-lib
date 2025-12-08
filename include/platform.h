#ifndef PLATFORM_H
#define PLATFORM_H

#include <string>

namespace platform
{
    std::string getPlatform();
    std::string getArchitecture();
    std::string getBitness();

    namespace compiler
    {
        std::string getCompiler();
    }

    std::string getOS();
}

#endif // PLATFORM_H
