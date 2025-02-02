#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

int main(int argc, char *argv[]) {
  if (argc < 1) {
    printf("Usage: calculate <length> ");
  }

  int n = std::atoi(argv[1]);
  auto range = std::views::iota(1, n);
  std::vector<int> result(range.size());
  std::partial_sum(range.begin(), range.end(), result.begin());
  printf("%d\n", std::accumulate(result.begin(), result.end(), 0));

  return 0;
}
