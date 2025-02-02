#include <iostream>
#include <ranges>

int main() {
  int current, max = INT_MIN, size = 3;

  std::cout << "Give me " << size
            << " numbers and I'll tell you which one is the greatest "
               "of them... ";

  for (const int i : std::views::iota(0, size)) {
    std::cin >> current;

    if (std::cin.fail()) {
      std::cout << "Failed to read the input.\n";
      return 1;
    }

    if (current > max)
      max = current;
  }

  std::cout << max << " is the gratest of them all." << std::endl;
}
