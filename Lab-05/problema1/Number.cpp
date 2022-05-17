#include "Number.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

const char base_matrix[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                            '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int get_val_base(char num) {
  if (num >= '0' && num <= '9') {
    return num - '0';
  }

  return num - 'A';
}

int convert_to_b10(char* c, int base) {
  int value = 0;
  int power = 1;
  int size = strlen(c);

  for (int i = 0; i < size; i++) {
    value += get_val_base(c[size - i - 1]) * power;
    power *= base;
  }

  return value;
}

char* convert_to_array(int value, int base) {
  char* val = (char*)calloc(1, 1);

  int current_length = 1;
  do {
    val = (char*)realloc(val, current_length + 1);
    int current_val = base_matrix[value % base];
    val[current_length++ - 1] = current_val;
    value /= base;
  } while (value);

  int size = strlen(val);
  for (int i = 0; i < size / 2; i++) {
    char temp = val[i];
    val[i] = val[size - i - 1];
    val[size - i - 1] = temp;
  }

  return val;
}

Number::Number(const char* value, int base) : current_base(base) {
  int length = strlen(value);
  val = (char*)calloc(length + 1, 1);

  strcpy(val, value);
}

Number& Number::operator=(Number&& ex) {
  this->val = convert_to_array(convert_to_b10(ex.val, ex.current_base),
                               ex.current_base);

  this->current_base = ex.current_base;

  return *this;
}

Number::Number(int num) {
  this->val = convert_to_array(num, 10);
  this->current_base = 10;
}

Number::Number(const char* value) : Number(value, 10) {}

Number::Number(const Number& num) {
  int length = strlen(num.val);
  this->val = (char*)calloc(length + 1, 1);

  strcpy(this->val, num.val);
  this->current_base = num.current_base;
}

Number::Number(const Number&& num) {
  this->val = num.val;
  this->current_base = num.current_base;
}

Number::~Number() { free(this->val); }

int Number::operator[](int index) { return this->val[index]; }

bool Number::operator<(Number i) {
  return convert_to_b10(this->val, this->current_base) <
         convert_to_b10(i.val, i.current_base);
}

bool Number::operator>(Number i) {
  return convert_to_b10(this->val, this->current_base) >
         convert_to_b10(i.val, i.current_base);
}

bool Number::operator<=(Number i) {
  return convert_to_b10(this->val, this->current_base) <=
         convert_to_b10(i.val, i.current_base);
}

bool Number::operator>=(Number i) {
  return convert_to_b10(this->val, this->current_base) >=
         convert_to_b10(i.val, i.current_base);
}

bool Number::operator==(Number i) {
  return convert_to_b10(this->val, this->current_base) ==
         convert_to_b10(i.val, i.current_base);
}

void Number::SwitchBase(int newBase) {
  this->val =
      convert_to_array(convert_to_b10(this->val, this->current_base), newBase);

  this->current_base = newBase;
}

void Number::Print() { printf("%s\n", this->val); }

int Number::GetDigitsCount() { return strlen(this->val); }

int Number::GetBase() { return current_base; }

Number operator-(Number num, Number val) {
  return (convert_to_array(convert_to_b10(num.val, num.current_base) -
                               convert_to_b10(val.val, val.current_base),
                           std::max(num.current_base, val.current_base)),
          std::max(num.current_base, val.current_base));
}

Number operator+(Number num, Number val) {
  return (convert_to_array(convert_to_b10(num.val, num.current_base) +
                               convert_to_b10(val.val, val.current_base),
                           std::max(num.current_base, val.current_base)),
          std::max(num.current_base, val.current_base));
}

Number& Number::operator+=(const Number& num) {
  this->val = convert_to_array(convert_to_b10(this->val, this->current_base) +
                                   convert_to_b10(num.val, num.current_base),
                               std::max(num.current_base, this->current_base));
  this->current_base = std::max(num.current_base, this->current_base);
  return *this;
}

void Number::operator--() {
  int length = strlen(this->val);
  char* temp = (char*)calloc(length + 1, 1);

  strncpy(temp, this->val, length - 1);
  strcpy(this->val, temp);

  free(temp);
}

void Number::operator--(int) {
  int length = strlen(this->val);
  char* temp = (char*)calloc(length + 1, 1);

  strcpy(temp, this->val + 1);
  strcpy(this->val, temp);

  free(temp);
}
