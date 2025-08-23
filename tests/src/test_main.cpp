//#define CATCH_CONFIG_MAIN
//#define CATCH_CONFIG_RUNNER
#include <catch2/catch_all.hpp>

#include <iostream>


TEST_CASE("TestMain", "[math]") {
    std::cout << "Running BasicTest" << std::endl;
    REQUIRE(1 + 1 == 2);
}