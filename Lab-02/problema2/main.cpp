#include <cstdio>

#include "globals.h"

int main() {
  Student s1, s2;

  s1.setName("John");
  s1.setMathGrade(9.3);
  s1.setEnglishGrade(7.5);
  s1.setHistoryGrade(5.45);

  s2.setName("Mike");
  s2.setMathGrade(9);
  s2.setEnglishGrade(7.5);
  s2.setHistoryGrade(7);

  printf("Student 1: \n");
  printf("%s %f %f %f %f\n", s1.getName(), s1.getMathGrade(),
         s1.getEnglishGrade(), s1.getHistoryGrade(), s1.getAverageGrade());

  printf("\nStudent 2: \n");
  printf("%s %f %f %f %f\n", s2.getName(), s2.getMathGrade(),
         s2.getEnglishGrade(), s2.getHistoryGrade(), s2.getAverageGrade());

  printf("compare name: %d\n", cmp_name(&s1, &s2));
  printf("compare math grade: %d\n", cmp_math(&s1, &s2));
  printf("compare english grade: %d\n", cmp_english(&s1, &s2));
  printf("compare history grade: %d\n", cmp_history(&s1, &s2));
  printf("compare average grade: %d\n", cmp_average(&s1, &s2));
}