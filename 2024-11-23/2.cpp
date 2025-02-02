#include <iostream>
#include <map>
#include <ranges>

int main() {
  int size;
  int *numbers = new int();

  std::cout << "\nPlease enter a size of the list (int): ";

  while (!(std::cin >> size) || size < 0) {
    std::cout << "\nInvalid list size. Please enter a non negative integeer: ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  std::cout << "Input the list: ";
  // TODO: Handle invalid data :D
  for (int i = 0; i < size; i++) {
    std::cin >> numbers[i];
  }

  std::map<int, size_t> map;
  int number;

  for (size_t i = 0; i < size; i++) {
    number = numbers[i];

    if (!map.count(number)) {
      map.insert({number, 1});
      continue;
    }

    map[number] += 1;
  }

  std::cout << "The most common element is: "
            << std::max_element(map.begin(), map.end())->second
            << ", it occured "
            << std::max_element(map.begin(), map.end())->first << " times :O"
            << std::endl;

  return 0;
}
