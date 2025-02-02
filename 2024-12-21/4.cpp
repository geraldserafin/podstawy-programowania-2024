#include <iostream>

int main() {
  size_t n;
  std::string string, output = "";

  std::cout << "Podaj napis: ";
  std::cin >> string;

  std::cout << "Podaj n: ";
  std::cin >> n;

  for (size_t i = 0; i < n; i++) {
    output += string;
  }

  std::cout << "Napis koncowy: " << output;

  return 0;
}
