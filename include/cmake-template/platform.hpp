#ifndef CMAKE_TEMPLATE_PLATFORM_HPP
#define CMAKE_TEMPLATE_PLATFORM_HPP

// Detect platform
#if defined(_WIN32) || defined(_WIN64)
#define PLATFORM_WINDOWS
#elif defined(__APPLE__) || defined(__MACH__)
#define PLATFORM_MACOS
#elif defined(__linux__)
#define PLATFORM_LINUX
#elif defined(__unix__)
#define PLATFORM_UNIX
#else
#define PLATFORM_UNKNOWN
#endif

// Detect architecture
#if defined(__x86_64__) || defined(_M_X64) || defined(_M_AMD64)
#define ARCH "x86_64"
#elif defined(__i386__) || defined(_M_IX86)
#define ARCH "x86"
#elif defined(__aarch64__) || defined(_M_ARM64)
#define ARCH "ARM64"
#elif defined(__arm__) || defined(_M_ARM)
#define ARCH "ARM"
#else
#define ARCH "Unknown Architecture"
#endif

// Detect compiler
#if defined(__clang__)
#define COMPILER "Clang " __clang_version__
#elif defined(__GNUC__) || defined(__GNUG__)
#define COMPILER "GCC " __VERSION__
#elif defined(_MSC_VER)
#define COMPILER "MSVC"
#else
#define COMPILER "Unknown Compiler"
#endif

// Detect C++ standard version
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

#endif  // CMAKE_TEMPLATE_PLATFORM_HPP
