#include <catch2/catch_all.hpp>
#include <cmake-template/code-style.hpp>
#include <cmake-template/library.hpp>

TEST_CASE("TestLibrary", "[math]")
{
  REQUIRE(Factorial(5) == 120);
  REQUIRE(FactorialInline(5) == 120);
  REQUIRE(FactorialConstexpr(5) == 120);
  REQUIRE(Factorial(-1) == 1);
  REQUIRE(FactorialInline(1) == 1);
  REQUIRE(FactorialInline(0) == 1);
  TestTreeFunction();
}
