#include <_types/_uint8_t.h>
#include <iostream>
#include <map>
#include <sys/_types/_size_t.h>

const size_t STUDENTS_NUMBER = 6;

namespace ClassNames {

const std::string INF = "informatyka";
const std::string MATH = "matematyka";
const std::string BIO = "biologia";
const std::string POL = "polski";

} // namespace ClassNames

struct Student {
  std::string name;
  std::map<std::string, size_t> grades = {{"informatyki", NULL},
                                          {"matematyki", NULL},
                                          {"biologii", NULL},
                                          {"polskiego", NULL}};
};

Student readStudent() {
  Student student = {};

  std::cout << "Podaj imie studenta: ";
  std::cin >> student.name;

  std::cout << "Ocena z infy: ";
  std::cin >> student.grades[ClassNames::INF];

  std::cout << "Ocena z matmy: ";
  std::cin >> student.grades[ClassNames::MATH];

  std::cout << "Ocena z biologii: ";
  std::cin >> student.grades[ClassNames::BIO];

  std::cout << "Ocena z polskiego: ";
  std::cin >> student.grades[ClassNames::POL];

  return student;
}

void question(Student *students) {
  size_t student_number, class_number;

  while (true) {
    std::cout << "Podaj number studenta [1..6]: ";
    std::cin >> student_number;

    if (student_number > 1 && student_number < STUDENTS_NUMBER) {
      break;
    }

    std::cout << "Zly numer, mowilem ze od 1 do 6... ";
  }

  Student student = students[student_number - 1];

  while (true) {
    std::cout << "Podaj number studenta [1..4]: ";
    std::cin >> class_number;

    if (class_number > 1 && class_number < student.grades.size()) {
      break;
    }

    std::cout << "Zly numer, mowilem ze od 1 do " << student.grades.size()
              << "...";
  }

  std::string class_name;

  switch (class_number) {
  case 1:
    class_name = ClassNames::INF;
    break;
  case 2:
    class_name = ClassNames::MATH;
    break;
  case 3:
    class_name = ClassNames::BIO;
    break;
  case 4:
    class_name = ClassNames::POL;
    break;
  }

  std::cout << "Uczen: " << student.name << ", ocena z " << class_name << ": "
            << student.grades[class_name] << std::endl;
}

int main() {
  size_t questions_number;
  Student students[STUDENTS_NUMBER];

  for (size_t i = 0; i < STUDENTS_NUMBER; i++) {
    students[i] = readStudent();
  }

  std::cout << "Podaj liczbe zapytan: ";
  std::cin >> questions_number;

  for (size_t i = 0; i < questions_number; i++) {
    question(students);
  }

  return 0;
}
