cmake_minimum_required (VERSION 3.30 FATAL_ERROR)

if (NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 23)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

project(
    cmake-template
    VERSION 0.0.1
    DESCRIPTION "A simple CMake project template"
    LANGUAGES CXX
)

set(CMAKE_TEMPLATE_IS_MAIN_PROJECT PROJECT_IS_TOP_LEVEL)

mark_as_advanced(${PROJECT_NAME}_FOUND)
mark_as_advanced(${PROJECT_NAME}_VERSION)
mark_as_advanced(${PROJECT_NAME}_DIR)


include(cmake/vcpkg.cmake)
include(cmake/spdlog.cmake)

add_subdirectory(src)

if (NOT PROJECT_IS_TOP_LEVEL)
    return()
endif()

# Testing
#if (BUILD_TESTING)
    enable_testing()
    include(cmake/catch2.cmake)
    add_subdirectory(tests)
#endif()

