#include <catch2/catch_all.hpp>

#include <cmake-template/library.hpp>

#ifdef CMAKE_TEMPLATE_HEADER_ONLY
TEST_CASE("TestLibraryHeaderOnly", "[math]") {
    REQUIRE(factorial_inline(5) == 120);
    REQUIRE(factorial_constexpr(5) == 120);
}
#else
TEST_CASE("TestLibrary", "[math]") {
    REQUIRE(factorial(5) == 120);
    REQUIRE(factorial_inline(5) == 120);
    REQUIRE(factorial_constexpr(5) == 120);
}
#endif

