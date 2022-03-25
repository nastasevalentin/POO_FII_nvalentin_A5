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
  this->current_base = newBase;
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
const char base_matrix[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                            '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
Number Number::operator+(const Number& i) {
  char s[100];
  int x = 0;
  strcpy(s, val);
  for (int i = 0; i < strlen(s); i++) x = x * 10 + (s[i] - '0');
  int y = 0;
  strcpy(s, i.val);
  for (int i = 0; i < strlen(s); i++) y = y * 10 + (s[i] - '0');
  x = x + y;
  char* val = (char*)calloc(1, 1);

  int current_length = 1;
  do {
    val = (char*)realloc(val, current_length + 1);
    int current_val = base_matrix[x % this->current_base];
    val[current_length++ - 1] = current_val;
    x /= this->current_base;
  } while (x);

  int size = strlen(val);
  for (int i = 0; i < size / 2; i++) {
    char temp = val[i];
    val[i] = val[size - i - 1];
    val[size - i - 1] = temp;
  }
  this->val = val;
  return Number(this->val, this->current_base);
}

Number Number::operator-(const Number& i) {
  char s[100];
  int x = 0;
  strcpy(s, val);
  for (int i = 0; i < strlen(s); i++) x = x * 10 + (s[i] - '0');
  int y = 0;
  strcpy(s, i.val);
  for (int i = 0; i < strlen(s); i++) y = y * 10 + (s[i] - '0');
  x = x - y;
  char* val = (char*)calloc(1, 1);

  int current_length = 1;
  do {
    val = (char*)realloc(val, current_length + 1);
    int current_val = base_matrix[x % this->current_base];
    val[current_length++ - 1] = current_val;
    x /= this->current_base;
  } while (x);

  int size = strlen(val);
  for (int i = 0; i < size / 2; i++) {
    char temp = val[i];
    val[i] = val[size - i - 1];
    val[size - i - 1] = temp;
  }
  this->val = val;
  return Number(this->val, this->current_base);
}

Number Number::operator=(int i) {
  int y = 0;
  char s[100];
  int p = 1;

  while (i) {
    y = y + p * (i % current_base);
    p = p * 10;
    i = i / current_base;
  }
  this->val = 0;
  char* val = (char*)calloc(1, 1);

  int current_length = 1;
  do {
    val = (char*)realloc(val, current_length + 1);
    int current_val = base_matrix[y % this->current_base];
    val[current_length++ - 1] = current_val;
    y /= this->current_base;
  } while (y);

  int size = strlen(val);
  for (int i = 0; i < size / 2; i++) {
    char temp = val[i];
    val[i] = val[size - i - 1];
    val[size - i - 1] = temp;
  }
  this->val = val;
  return Number(this->val, this->current_base);
}

Number Number::operator++(int i) {
  char s[100];
  int x = 0;
  strcpy(s, val);
  for (int i = 0; i < strlen(s); i++) x = x * 10 + (s[i] - '0');
  x++;
  char* val = (char*)calloc(1, 1);

  int current_length = 1;
  do {
    val = (char*)realloc(val, current_length + 1);
    int current_val = base_matrix[x % this->current_base];
    val[current_length++ - 1] = current_val;
    x /= this->current_base;
  } while (x);

  int size = strlen(val);
  for (int i = 0; i < size / 2; i++) {
    char temp = val[i];
    val[i] = val[size - i - 1];
    val[size - i - 1] = temp;
  }
  this->val = val;
  return Number(this->val, this->current_base);
}

Number Number::operator--() {
  char s[100];
  int x = 0;
  strcpy(s, val);
  for (int i = 0; i < strlen(s); i++) x = x * 10 + (s[i] - '0');

  x = x / 10;

  char* val = (char*)calloc(1, 1);

  int current_length = 1;
  do {
    val = (char*)realloc(val, current_length + 1);
    int current_val = base_matrix[x % this->current_base];
    val[current_length++ - 1] = current_val;
    x /= this->current_base;
  } while (x);

  int size = strlen(val);
  for (int i = 0; i < size / 2; i++) {
    char temp = val[i];
    val[i] = val[size - i - 1];
    val[size - i - 1] = temp;
  }
  this->val = val;
  return Number(this->val, this->current_base);
}
Number Number::operator--(int i) {
  char s[100];
  int x = 0;
  int p = 1;
  strcpy(s, val);
  for (int i = 0; i < strlen(s); i++) {
    x = x * 10 + (s[i] - '0');
    p = p * 10;
  }
  p = p / 10;
  x = x % p;

  char* val = (char*)calloc(1, 1);

  int current_length = 1;
  do {
    val = (char*)realloc(val, current_length + 1);
    int current_val = base_matrix[x % this->current_base];
    val[current_length++ - 1] = current_val;
    x /= this->current_base;
  } while (x);

  int size = strlen(val);
  for (int i = 0; i < size / 2; i++) {
    char temp = val[i];
    val[i] = val[size - i - 1];
    val[size - i - 1] = temp;
  }
  this->val = val;
  return Number(this->val, this->current_base);
}

Number Number::operator=(const char* i) { strcpy(val, i); }

Number Number::operator+=(const Number& i) {
  char s[100];
  int x = 0;
  strcpy(s, val);
  for (int i = 0; i < strlen(s); i++) x = x * 10 + (s[i] - '0');
  int y = 0;
  strcpy(s, i.val);
  for (int i = 0; i < strlen(s); i++) y = y * 10 + (s[i] - '0');
  x = x + y;
  char* val = (char*)calloc(1, 1);

  int current_length = 1;
  do {
    val = (char*)realloc(val, current_length + 1);
    int current_val = base_matrix[x % this->current_base];
    val[current_length++ - 1] = current_val;
    x /= this->current_base;
  } while (x);

  int size = strlen(val);
  for (int i = 0; i < size / 2; i++) {
    char temp = val[i];
    val[i] = val[size - i - 1];
    val[size - i - 1] = temp;
  }
  this->val = val;
  return Number(this->val, this->current_base);
}

Number Number::operator-=(const Number& i) {
  char s[100];
  int x = 0;
  strcpy(s, val);
  for (int i = 0; i < strlen(s); i++) x = x * 10 + (s[i] - '0');
  int y = 0;
  strcpy(s, i.val);
  for (int i = 0; i < strlen(s); i++) y = y * 10 + (s[i] - '0');
  x = x - y;
  char* val = (char*)calloc(1, 1);

  int current_length = 1;
  do {
    val = (char*)realloc(val, current_length + 1);
    int current_val = base_matrix[x % this->current_base];
    val[current_length++ - 1] = current_val;
    x /= this->current_base;
  } while (x);

  int size = strlen(val);
  for (int i = 0; i < size / 2; i++) {
    char temp = val[i];
    val[i] = val[size - i - 1];
    val[size - i - 1] = temp;
  }
  this->val = val;
  return Number(this->val, this->current_base);
}

int Number::operator>(const Number& i) { return strcmp(val, i.val); }

void Number::Print() { cout << this->val; }

int Number::GetBase() { return this->current_base; }

int Number::GetDigitsCount() { return strlen(this->val); }
