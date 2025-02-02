#include <iostream>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Pizza slices calculator\n\nUsage: pizza <Pizzas to devide> <People "
           "to feed>\n");
  }

  int slices = 8 * std::atoi(argv[1]);
  int people = std::atoi(argv[2]);

  printf("Total slices: %d,\nSlices per person: %d,\nUnused slices: %d\n",
         slices, slices / people, slices % people);

  return 0;
}
