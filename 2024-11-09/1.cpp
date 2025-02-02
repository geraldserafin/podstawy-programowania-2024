#include <exception>
#include <expected>
#include <iomanip>
#include <iostream>
#include <optional>
#include <ostream>
#include <utility>

std::expected<float, std::string>
readFloat(std::optional<std::string> message = std::nullopt) {
  std::string input;

  std::cout << message.value_or("Enter a float... ");
  std::cin >> input;

  try {
    return std::stof(input);
  } catch (std::invalid_argument) {
    return std::unexpected("Invalid float");
  }
}

int main() {
  auto result = readFloat().and_then([](float a) {
    return readFloat().transform([a](float b) { return std::pair(a, b); });
  });

  auto sum =
      result.transform([](auto pair) { return pair.first + pair.second; });

  auto diff =
      result.transform([](auto pair) { return pair.first - pair.second; });

  auto product =
      result.transform([](auto pair) { return pair.first * pair.second; });

  auto div =
      result
          .and_then([](auto pair)
                        -> std::expected<std::pair<float, float>, std::string> {
            if (pair.second == 0) {
              return std::unexpected("Cannot div by 0");
            }
            return pair;
          })
          .transform([](auto pair) { return pair.first / pair.second; });

  return 0;
}
