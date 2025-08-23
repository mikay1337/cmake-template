cmake_minimum_required (VERSION 3.30)



set(tests_src
    test_main.cpp
)   




foreach(test_src IN LISTS tests_src)

    get_filename_component(exename ${test_src} NAME_WE)
    add_executable(${exename} src/${test_src})
    target_link_libraries(${exename}
        PRIVATE 
            Catch2::Catch2
            Catch2::Catch2WithMain
    )
    set_target_properties(${exename} PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
    )
    if (MSVC)
        target_compile_options(${exename} PRIVATE /W4 /WX)
    else()
        target_compile_options(${exename} PRIVATE -Wall -Wextra -Wpedantic -Werror)
    endif()

    add_test(NAME ${exename} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR} COMMAND ${exename})



endforeach()
