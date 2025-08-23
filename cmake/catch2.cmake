
#Check if catch2 is already available
if (TARGET Catch2::Catch2)
    return()
endif()
find_package(Catch2 QUIET)

if (TARGET Catch2::Catch2)
    return()
endif()

include(FetchContent)
FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.9.0
)   
FetchContent_MakeAvailable(Catch2)
