#include <iostream>
#include <ranges>
#include <string>

int main() {
  int n;

  std::cin >> n;

  if (std::cin.fail()) {
    std::cout << "Wrong input" << std::endl;
    return 1;
  }

  auto filter = [](int i) { return i % 5 == 0 && i % 3 != 0; };

  for (int i : std::views::iota(1, n) | std::views::filter(filter)) {
    std::cout << i << std::endl;
  }

  return 0;
}
