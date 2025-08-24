#ifndef CMAKE_TEMPLATE_HEADER_ONLY

#include <cmake-template/library.hpp>

[[nodiscard]] auto factorial(int n) noexcept -> int
{
    return factorial_inline(n);
}
#endif