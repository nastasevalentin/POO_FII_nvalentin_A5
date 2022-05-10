#include "globals.h"

#include <cstring>

int cmp_name(Student* s1, Student* s2) {
  if (strcmp(s1->getName(), s2->getName()) < 0) {
    return -1;
  }

  return strcmp(s1->getName(), s2->getName()) != 0;
}

int cmp_math(Student* s1, Student* s2) {
  if (s1->getMathGrade() < s2->getMathGrade()) {
    return -1;
  }

  return s1->getMathGrade() != s2->getMathGrade();
}

int cmp_english(Student* s1, Student* s2) {
  if (s1->getEnglishGrade() < s2->getEnglishGrade()) {
    return -1;
  }

  return s1->getEnglishGrade() != s2->getEnglishGrade();
}

int cmp_history(Student* s1, Student* s2) {
  if (s1->getHistoryGrade() < s2->getHistoryGrade()) {
    return -1;
  }

  return s1->getHistoryGrade() != s2->getHistoryGrade();
}

int cmp_average(Student* s1, Student* s2) {
  if (s1->getAverageGrade() < s2->getAverageGrade()) {
    return -1;
  }

  return s1->getAverageGrade() != s2->getAverageGrade();
}