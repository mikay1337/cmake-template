
if (TARGET spdlog::spdlog)
    return()
endif()

find_package(spdlog QUIET)

if (TARGET spdlog::spdlog)
    return()
endif()

include(FetchContent)
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG        1.15.3
)
FetchContent_MakeAvailable(spdlog)


