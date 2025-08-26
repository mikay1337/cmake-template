#ifndef CMAKE_TEMPLATE_LIBRARY_HPP
#define CMAKE_TEMPLATE_LIBRARY_HPP

#include <cmake-template/common.hpp>

[[nodiscard]] inline auto FactorialInline(int n) noexcept -> int
{
  return (n <= 1) ? 1 : (n * FactorialInline(n - 1));
}

[[nodiscard]] constexpr auto FactorialConstexpr(int n) noexcept -> int
{
  return (n <= 1) ? 1 : (n * FactorialConstexpr(n - 1));
}

[[nodiscard]] CMAKE_TEMPLATE_API auto Factorial(int n) noexcept -> int;

#endif  // CMAKE_TEMPLATE_LIBRARY_HPP