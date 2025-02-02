#include <iostream>
#include <ranges>

int main() {
  enum Sign { NEGATIVE, POSITIVE, ZERO };

  auto signum = [](int i) {
    return i < 0 ? NEGATIVE : i > 0 ? POSITIVE : ZERO;
  };

  int input;

  std::cout << "Enter a number and i'll tell you if it's positive... ";
  std::cin >> input;

  if (std::cin.fail()) {
    std::cout << "Failed to read the input.\n";
    return 1;
  }

  Sign sign = signum(input);

  printf("This number is %s%s",
         sign == POSITIVE   ? "obviously positive"
         : sign == NEGATIVE ? "pretty negative"
                            : "nothing but zero",
         ".\n");
}
