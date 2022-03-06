#include "student.h"

#include <cstdlib>
#include <cstring>

Student::Student() {
  this->name = nullptr;
  this->math = 1;
  this->english = 1;
  this->history = 1;

  this->setName("Unnamed");
}

Student::~Student() {
  if (this->name) {
    free(this->name);
  }
}

char* Student::getName() { return this->name; }

void Student::setName(char* value) {
  int value_size = strlen(value);

  if (this->name) {
    free(this->name);
  }

  this->name = (char*)malloc(value_size + 1);
  strcpy(this->name, value);
}

float Student::getMathGrade() { return this->math; }

void Student::setMathGrade(float value) { this->math = value; }

float Student::getEnglishGrade() { return this->english; }

void Student::setEnglishGrade(float value) { this->english = value; }

float Student::getHistoryGrade() { return this->history; }

void Student::setHistoryGrade(float value) { this->history = value; }

float Student::getAverageGrade() {
  return (this->math + this->english + this->history) / 3;
}
