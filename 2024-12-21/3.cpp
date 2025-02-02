#include <algorithm>
#include <iostream>
#include <ranges>
#include <span>
#include <vector>

struct Student {
  std::string full_name;
  int index_number;
};

int main() {
  std::vector<Student> students = {{"Pola Kundo", 34551},
                                   {"Gerald Serafin", 34101}};

  std::cout << "Wektor przed posortowaniem: " << std::endl;

  for (auto student : students) {
    std::cout << student.index_number << " " << student.full_name << std::endl;
  }

  std::sort(students.begin(), students.end(), [](Student s1, Student s2) {
    return s1.index_number < s2.index_number;
  });

  std::cout << "\nWektor posortowany: " << std::endl;

  for (auto student : students) {
    std::cout << student.index_number << " " << student.full_name << std::endl;
  }

  return 0;
}
