#include <cmake-template/library.hpp>

auto factorial(int n) noexcept -> int
{
    return factorial_inline(n);
}