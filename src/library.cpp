#include <cmake-template/library.hpp>

int factorial(int n) noexcept
{
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}