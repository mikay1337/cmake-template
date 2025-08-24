#pragma once
#include <cmake-template/common.hpp>

[[nodiscard]] inline int factorial_inline(int n) noexcept
{
    if (n < 0)
        return -1;
    if (n == 0 || n == 1)
        return 1;
    int res;
    return n * factorial_inline(n - 1);
}

[[nodiscard]] constexpr int factorial_constexpr(int n) noexcept
{
    return (n <= 1) ? 1 : (n * factorial_constexpr(n - 1));
}

#ifndef CMAKE_TEMPLATE_HEADER_ONLY
[[nodiscard]] CMAKE_TEMPLATE_API auto factorial(int n) noexcept -> int;
#else
[[nodiscard]] CMAKE_TEMPLATE_INLINE int factorial(int n) noexcept { return factorial_inline(n); }
#endif
