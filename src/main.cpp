#include <iostream>
#include <string>
#include <array>
#include <bitset>
#include <cstring>
#include <fstream>
#include <sstream>

// ================= COMPILER DETECTION =================
#if defined(__clang__)
    #define COMPILER "Clang " __clang_version__
#elif defined(__GNUC__)
    #define COMPILER "GCC " __VERSION__
#elif defined(_MSC_VER)
    #define COMPILER "MSVC"
#else
    #define COMPILER "Unknown Compiler"
#endif

// ================= C++ VERSION DETECTION =================
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

// ================= ARCHITECTURE DETECTION =================
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

// ================= CPU INFO DETECTION =================
#if defined(_WIN32)
    #include <intrin.h>
    void print_cpu_info() {
        int cpuInfo[4] = { 0 };
        char vendor[13];

        __cpuid(cpuInfo, 0);
        std::memcpy(vendor, &cpuInfo[1], 4);
        std::memcpy(vendor + 4, &cpuInfo[3], 4);
        std::memcpy(vendor + 8, &cpuInfo[2], 4);
        vendor[12] = '\0';

        std::cout << "CPU Vendor: " << vendor << "\n";

        __cpuid(cpuInfo, 1);
        std::cout << "SSE:  " << ((cpuInfo[3] & (1 << 25)) ? "Yes" : "No") << "\n";
        std::cout << "SSE2: " << ((cpuInfo[3] & (1 << 26)) ? "Yes" : "No") << "\n";
        std::cout << "SSE3: " << ((cpuInfo[2] & (1 << 0)) ? "Yes" : "No") << "\n";
        std::cout << "SSSE3:" << ((cpuInfo[2] & (1 << 9)) ? "Yes" : "No") << "\n";
        std::cout << "SSE4.1:" << ((cpuInfo[2] & (1 << 19)) ? "Yes" : "No") << "\n";
        std::cout << "SSE4.2:" << ((cpuInfo[2] & (1 << 20)) ? "Yes" : "No") << "\n";
        std::cout << "AVX:  " << ((cpuInfo[2] & (1 << 28)) ? "Yes" : "No") << "\n";
    }
#elif defined(__linux__) || defined(__ANDROID__)
    void print_cpu_info() {
        std::ifstream cpuinfo("/proc/cpuinfo");
        if (!cpuinfo.is_open()) {
            std::cerr << "Tidak bisa membaca /proc/cpuinfo\n";
            return;
        }

        std::string line;
        std::cout << "=== /proc/cpuinfo ===\n";
        while (std::getline(cpuinfo, line)) {
            if (line.find("model name") != std::string::npos ||
                line.find("Hardware") != std::string::npos ||
                line.find("Processor") != std::string::npos ||
                line.find("Features") != std::string::npos) {
                std::cout << line << "\n";
            }
        }
        cpuinfo.close();
    }
#else
    void print_cpu_info() {
        std::cout << "CPU detection not supported on this platform.\n";
    }
#endif

// ================= MAIN =================
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

    return 0;
}
