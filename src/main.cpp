#include <iostream>
#include <string>
#include <array>
#include <bitset>
#include <cstring>

#define STRINGIFY(x) #x

#if defined(__GNUC__) && !defined(__clang__)
#define COMPILER "GCC " __VERSION__
#elif defined(__clang__)
#define COMPILER "Clang " __VERSION__
#elif defined(_MSC_VER)
#define COMPILER "MSVC "
#else
#define COMPILER "Unknown Compiler"
#endif

#if defined(_MSC_VER)
#define CPP_STD_VER _MSVC_LANG
#else
#define CPP_STD_VER __cplusplus
#endif

#if CPP_STD_VER == 201103L
#define CPP_VERSION "C++11"
#elif CPP_STD_VER == 201402L
#define CPP_VERSION "C++14"
#elif CPP_STD_VER == 201703L
#define CPP_VERSION "C++17"
#elif CPP_STD_VER == 202002L
#define CPP_VERSION "C++20"
#elif CPP_STD_VER > 202002L
#define CPP_VERSION "C++23 or newer"
#else
#define CPP_VERSION "Pre-C++11"
#endif

#if defined(_M_X64) || defined(__x86_64__)
#define ARCH "x86_64"
#elif defined(_M_IX86) || defined(__i386__)
#define ARCH "x86"
#elif defined(__aarch64__) || defined(_M_ARM64)
#define ARCH "ARM64"
#elif defined(__arm__) || defined(_M_ARM)
#define ARCH "ARM"
#else
#define ARCH "Unknown Architecture"
#endif

#ifdef _WIN32
#include <intrin.h>
void cpuid(int info[4], int id) {
    __cpuid(info, id);
}
#else
#include <cpuid.h>
void cpuid(int info[4], int id) {
    __cpuid_count(id, 0, info[0], info[1], info[2], info[3]);
}
#endif

void print_cpu_info() {
    int cpuInfo[4] = { 0 };
    char vendor[13];
    cpuid(cpuInfo, 0);
    std::memcpy(vendor, &cpuInfo[1], 4);
    std::memcpy(vendor + 4, &cpuInfo[3], 4);
    std::memcpy(vendor + 8, &cpuInfo[2], 4);
    vendor[12] = '\0';

    std::cout << "CPU Vendor: " << vendor << "\n";

    cpuid(cpuInfo, 1);
    std::cout << "SSE:  " << ((cpuInfo[3] & (1 << 25)) ? "Yes" : "No") << "\n";
    std::cout << "SSE2: " << ((cpuInfo[3] & (1 << 26)) ? "Yes" : "No") << "\n";
    std::cout << "SSE3: " << ((cpuInfo[2] & (1 << 0)) ? "Yes" : "No") << "\n";
    std::cout << "SSSE3:" << ((cpuInfo[2] & (1 << 9)) ? "Yes" : "No") << "\n";
    std::cout << "SSE4.1:" << ((cpuInfo[2] & (1 << 19)) ? "Yes" : "No") << "\n";
    std::cout << "SSE4.2:" << ((cpuInfo[2] & (1 << 20)) ? "Yes" : "No") << "\n";
    std::cout << "AVX:  " << ((cpuInfo[2] & (1 << 28)) ? "Yes" : "No") << "\n";

    cpuid(cpuInfo, 7);
    std::cout << "AVX2: " << ((cpuInfo[1] & (1 << 5)) ? "Yes" : "No") << "\n";
    std::cout << "BMI1: " << ((cpuInfo[1] & (1 << 3)) ? "Yes" : "No") << "\n";
    std::cout << "BMI2: " << ((cpuInfo[1] & (1 << 8)) ? "Yes" : "No") << "\n";

}

int main() {
    
    #ifdef NDEBUG
    std::cout << "Build Type: Release\n";
    #else
    std::cout << "Build Type: Debug\n";
    #endif
    

    std::cout << "Compiler: " << COMPILER << "\n";
    std::cout << "C++ Standard: " << CPP_VERSION << "\n";
    std::cout << "Architecture: " << ARCH << "\n\n";

    print_cpu_info();

    system("pause");

    return 0;
}
