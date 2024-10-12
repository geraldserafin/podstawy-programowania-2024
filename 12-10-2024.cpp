#include <iostream>
#include <ranges>

void zad2() {
  enum Sign { NEGATIVE, POSITIVE, ZERO };

  auto signum = [](int i) {
    return i < 0 ? NEGATIVE : i > 0 ? POSITIVE : ZERO;
  };

  int input;

  std::cout << "Enter a number and i'll tell you if it's positive... ";
  std::cin >> input;

  if (std::cin.fail()) {
    std::cout << "Failed to read the input.\n";
    return;
  }

  Sign sign = signum(input);

  printf("This number is %s%s",
         sign == POSITIVE   ? "obviously positive"
         : sign == NEGATIVE ? "pretty negative"
                            : "nothing but zero",
         ".\n");
}

void zad4(int size) {
  int current, max = INT_MIN;

  std::cout << "Give me " << size
            << " numbers and I'll tell you which one is the greatest "
               "of them... ";

  for (const int i : std::views::iota(0, size)) {
    std::cin >> current;

    if (std::cin.fail()) {
      std::cout << "Failed to read the input.\n";
      return;
    }

    if (current > max)
      max = current;
  }

  std::cout << max << " is the gratest of them all." << std::endl;
}

int main() {
  std::cout << "Gerald" << std::endl
            << 34101 << std::endl
            << "PJATK" << std::endl;

  zad2();

  zad4(3);
}
