#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>

int main() {

  int *numbers = new int();
  int size;

  std::cout << "\nPlease enter a size of the list (int): ";

  while (!(std::cin >> size) || size < 0) {
    std::cout << "\nInvalid list size. Please enter a non negative integeer: ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  // TODO: Handle invalid data :D
  for (auto i : std::views::iota(0, size)) {
    std::cin >> numbers[i];
  }

  std::ranges::copy(std::span(numbers, size),
                    std::ostream_iterator<int>(std::cout, " "));

  return 0;
}
