#include "platform.h"
#if defined(__APPLE__)
#include <TargetConditionals.h>
#endif
#include <iostream>

namespace platform
{
    std::string getPlatform()
    {
    #if defined(_WIN32) || defined(_WIN64)
        return "windows";
    #elif defined(__APPLE__) && defined(__MACH__)
        #if TARGET_IPHONE_SIMULATOR
            return "ios_simulator";
        #elif TARGET_OS_IPHONE
            return "ios";
        #elif TARGET_OS_MAC
            return "macos";
        #else
            return "apple_unknown";
        #endif
    #elif defined(__ANDROID__)
        return "android";
    #elif defined(__linux__)
        return "linux";
    #elif defined(__unix__)
        return "unix";
    #elif defined(__FreeBSD__)
        return "freebsd";
    #elif defined(__NetBSD__)
        return "netbsd";
    #elif defined(__OpenBSD__)
        return "openbsd";
    #elif defined(__sun)
        return "solaris";
    #else
        return "unknown";
    #endif
    }

    std::string getArchitecture()
    {
    #if defined(_M_X64) || defined(__x86_64__)
        return "x64";
    #elif defined(_M_IX86) || defined(__i386__)
        return "x86";
    #elif defined(__aarch64__) || defined(_M_ARM64)
        return "arm64";
    #elif defined(__arm__) || defined(_M_ARM)
        return "arm";
    #else
        return "unknown";
    #endif
    }

    std::string getBitness()
    {
        return (sizeof(void*) == 8) ? "64-bit" : "32-bit";
    }

    namespace compiler
    {
        std::string getCompiler()
        {
        #if defined(__clang__)
            return "clang";
        #elif defined(__GNUC__) || defined(__GNUG__)
            return "gcc";
        #elif defined(_MSC_VER)
            return "msvc";
        #else
            return "unknown";
        #endif
        }
    }

    std::string getOS()
    {
        return getPlatform() + " " + getArchitecture() + " " + getBitness() + " (" + compiler::getCompiler() + ")";
    }

} // namespace platform
