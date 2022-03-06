#pragma once

class Student {
  char* name;
  float math, english, history;

 public:
  Student();
  ~Student();

  char* getName();
  void setName(char* value);

  float getMathGrade();
  void setMathGrade(float value);

  float getEnglishGrade();
  void setEnglishGrade(float value);

  float getHistoryGrade();
  void setHistoryGrade(float value);

  float getAverageGrade();
};