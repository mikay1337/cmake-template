#ifndef CMAKE_TEMPLATE_CODE_STYLE_HPP
#define CMAKE_TEMPLATE_CODE_STYLE_HPP

#include <algorithm>
#include <cstdint>
#include <functional>
#include <iostream>
#include <memory>
#include <optional>
#include <string>
#include <utility>
#include <vector>

/**
 * @brief Class to test clang-tidy and clang-format with various C++ features.
 */
class MyClass
{
 public:
  MyClass() = default;
  ~MyClass() = default;

  MyClass(const MyClass&) = delete;
  auto operator=(const MyClass&) -> MyClass& = delete;

  MyClass(MyClass&&) noexcept = default;
  auto operator=(MyClass&&) noexcept -> MyClass& = default;

  /**
   * @brief A simple method demonstrating if-else, switch, lambda, and
   * structured binding.
   */
  [[nodiscard]] auto DoSomething(const std::string& input) const -> int
  {
    // If-else with spacing & clang-format test
    if (input.empty()) { return 0; }
    if (input.size() > 10) { return 10; }
    return static_cast<int>(input.size());
  }

  /**
   * @brief Demonstrates switch-case and clang-format indentation.
   */
  static auto SwitchCaseExample(int value) -> std::string
  {
    switch (value)
    {
      case 0: return "Zero";
      case 1:
      case 2: return "Small";
      case 3: return "Three";
      default: return "Other";
    }
  }

  /**
   * @brief Demonstrates use of lambda expressions and sorting.
   */
  static auto SortNumbers(std::vector<int> numbers)
  {
    std::ranges::sort(numbers, std::less{});
    return numbers;
  }

  /**
   * @brief Demonstrates inline constexpr function.
   */
  [[nodiscard]] static constexpr auto AddNumbers(int a, int b) noexcept -> int
  {
    return a + b;
  }

  /**
   * @brief Demonstrates optional return type and structured binding.
   */
  [[nodiscard]] static auto FindValue(
      const std::vector<std::pair<int, std::string>>& data, int key)
      -> std::optional<std::pair<int, std::string>>
  {
    for (const auto& [k, v] : data)
    {
      if (k == key) { return std::make_pair(k, v); }
    }
    return std::nullopt;
  }

  /**
   * @brief Demonstrates usage of unique_ptr and lambda capture.
   */
  void ProcessWithCallback(std::unique_ptr<int> value,
                           const std::function<void(int)>& callback)
  {
    if (value) { callback(*value); }
    ++member_variable_;
  }

 private:
  int member_variable_{0};
};

/**
 * @brief Example struct with enum class, template, and specialization.
 */
struct MyStruct
{
  enum class Status : std::uint8_t
  {
    Ok,
    Warning,
    Error
  };

  template <typename T>
  static auto Max(T a, T b) -> T
  {
    return (a > b) ? a : b;
  }

  // Specialization example for int
  static auto Max(int a, int b) -> int { return std::max(a, b); }

  Status status{Status::Ok};
  int member_variable = 0;
};

/**
 * @brief Free function demonstrating lambda, auto, and range-based for.
 */
inline void TestTreeFunction()
{
  std::vector<int> values = {5, 2, 8, 1};

  // Inline lambda for sorting
  std::ranges::sort(values);

  // Range-based for loop
  for (const auto& v : values) { std::cout << v << " "; }
  std::cout << "\n";
}

#endif  // CMAKE_TEMPLATE_CODE_STYLE_HPP