#pragma once
#include <cmake-template/common.hpp>

[[nodiscard]] inline auto factorial_inline(int n) noexcept -> int
{
    if (n < 0)
    {
        return -1;
    }
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * factorial_inline(n - 1);
}

[[nodiscard]] constexpr auto factorial_constexpr(int n) noexcept -> int
{
    return (n <= 1) ? 1 : (n * factorial_constexpr(n - 1));
}

[[nodiscard]] CMAKE_TEMPLATE_API auto factorial(int n) noexcept -> int;
