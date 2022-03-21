#include "Number.h"

#include <stdlib.h>

#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;

Number::Number(const char* value, int base) {
  int length = strlen(value);
  val = (char*)malloc(length + 1);

  strcpy(val, value);
  current_base = base;
}

void Number::SwitchBase(int newBase) {
  char s[100];
  int x = 0;
  int n1 = 0;
  int p = 1;
  strcpy(s, this->val);
  for (int i = 0; i < strlen(s); i++) x = x * 10 + (s[i] - '0');
  while (x) {
    n1 = n1 + (x % 10) * p;
    p = p * this->current_base;
    x = x / 10;
  }
  p = 1;
  while (n1) {
    x = x + p * (n1 % newBase);
    p = p * 10;
    n1 = n1 / newBase;
  }
  stringstream newValue;
  newValue << x;
  newValue >> this->val;
}
/*
int Number::operator+(const Number& i) {
  if (i.current_base > current_base) {
    i.SwitchBase(current_base);
  } else if (i.current_base < current_base) {
    SwitchBase(n2.current_base);
  }
}*/

int Number::operator>(const Number& i) { return strcmp(val, i.val); }
