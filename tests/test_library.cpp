#include <catch2/catch_all.hpp>

#include <cmake-template/library.hpp>

TEST_CASE("TestLibrary", "[math]") {
    REQUIRE(factorial(5) == 120);
    REQUIRE(factorial_inline(5) == 120);
    REQUIRE(factorial_constexpr(5) == 120);
    REQUIRE(factorial(-1) == -1);
    REQUIRE(factorial(1) == 1);
    REQUIRE(factorial(0) == 1);
}
