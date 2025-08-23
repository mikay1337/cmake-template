
set(CMAKE_TOOLCHAIN_FILE "$ENV:VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
set(VCPKG_TARGET_TRIPLET "x64-windows" CACHE STRING "Vcpkg target triplet")
set(VCPKG_OVERLAY_TRIPLET "$ENV:VCPKG_ROOT/triplets" CACHE STRING "Vcpkg overlay triplet")