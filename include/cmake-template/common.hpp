#ifndef CMAKE_TEMPLATE_COMMON_HPP
#define CMAKE_TEMPLATE_COMMON_HPP

#ifdef CMAKE_TEMPLATE_COMPILED_LIB
#ifdef CMAKE_TEMPLATE_SHARED
#ifdef _WIN32
#ifdef cmake_template_EXPORTS
#define CMAKE_TEMPLATE_API __declspec(dllexport)
#else
#define CMAKE_TEMPLATE_API __declspec(dllimport)
#endif
#else
#define CMAKE_TEMPLATE_API __attribute__((visibility("default")))
#endif
#else
#define CMAKE_TEMPLATE_API
#endif
#define CMAKE_TEMPLATE_INLINE
#else
#define CMAKE_TEMPLATE_API
#define CMAKE_TEMPLATE_INLINE inline
#define CMAKE_TEMPLATE_HEADER_ONLY
#endif

#endif  // CMAKE_TEMPLATE_COMMON_HPP
