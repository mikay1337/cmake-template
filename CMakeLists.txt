cmake_minimum_required (VERSION 3.30 FATAL_ERROR)

#==============================================================================
# C++ Standard
#==============================================================================
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

#==============================================================================
# Project configuration
#==============================================================================
set(CMAKE_INSTALL_INCLUDEDIR include)
mark_as_advanced(${PROJECT_NAME}_FOUND)
mark_as_advanced(${PROJECT_NAME}_VERSION)
mark_as_advanced(${PROJECT_NAME}_DIR)

#==============================================================================
# Options
#==============================================================================
option(CMAKE_TEMPLATE_BUILD_SHARED "Build ${PROJECT_NAME} as shared library" OFF)
option(CMAKE_TEMPLATE_BUILD_TESTS "Build tests" ON)
option(CMAKE_TEMPLATE_BUILD_BENCHMARKS "Build benchmarks" OFF)
option(CMAKE_TEMPLATE_INSTALL "Install ${PROJECT_NAME}" ON)

#==============================================================================
# Dependencies
#==============================================================================
#include(cmake/spdlog.cmake)
#add_subdirectory(thirdparty)

#==============================================================================
# Static/Shared library
#==============================================================================
set(CMAKE_TEMPLATE_SRCS
    src/library.cpp
)

if (CMAKE_TEMPLATE_BUILD_SHARED OR BUILD_SHARED_LIBS)
    add_library(${PROJECT_NAME} SHARED ${CMAKE_TEMPLATE_SRCS} ${CMAKE_TEMPLATE_HEADERS})
    target_compile_definitions(${PROJECT_NAME} PUBLIC CMAKE_TEMPLATE_SHARED)
else()
    add_library(${PROJECT_NAME} STATIC ${CMAKE_TEMPLATE_SRCS} ${CMAKE_TEMPLATE_HEADERS})
endif()

target_compile_definitions(${PROJECT_NAME} PUBLIC CMAKE_TEMPLATE_COMPILED_LIB)
target_include_directories(${PROJECT_NAME} 
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

#==============================================================================
# Header-only library target
#==============================================================================
add_library(${PROJECT_NAME}_header_only INTERFACE)
target_include_directories(${PROJECT_NAME}_header_only 
    INTERFACE 
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

#=============================================================================
# Generate clangd configuration
#=============================================================================
configure_file(.clangd.in ${CMAKE_SOURCE_DIR}/.clangd @ONLY)

#==============================================================================
# Tests
#==============================================================================
if (CMAKE_TEMPLATE_BUILD_TESTS OR BUILD_TESTING)
    enable_testing()
    include(cmake/catch2.cmake)
    add_subdirectory(tests)
endif()

#==============================================================================
# Benchmarks
#==============================================================================
#if (CMAKE_TEMPLATE_BUILD_BENCHMARKS)
#    add_subdirectory(benchmarks)
#endif()


#==============================================================================
# Installation
#==============================================================================
if (CMAKE_TEMPLATE_INSTALL)
    message(STATUS "Configuring installation of the project")

endif()