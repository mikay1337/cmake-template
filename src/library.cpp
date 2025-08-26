#include <cmake-template/library.hpp>

[[nodiscard]] auto Factorial(int n) noexcept -> int
{
  return FactorialInline(n);
}
