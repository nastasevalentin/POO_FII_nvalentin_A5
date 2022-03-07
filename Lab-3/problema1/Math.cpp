#include "Math.h"

#include <stdlib.h>

#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstring>

int Math::Add(int x, int y) { return x + y; }

int Math::Add(int x, int y, int z) { return x + y + z; }

int Math::Add(double x, double y) { return x + y; }

int Math::Add(double x, double y, double z) { return x + y + z; }

int Math::Mul(int x, int y) { return x + y; }

int Math::Mul(int x, int y, int z) { return x + y + z; }

int Math::Mul(double x, double y) { return x + y; }

int Math::Mul(double x, double y, double z) { return x + y + z; }

int Math::Add(int count, ...) {
  int sum = 0;
  va_list vl;
  va_start(vl, count);
  for (int i = 0; i < count; i++) {
    sum += va_arg(vl, int);
  }
  va_end(vl);
  return sum;
}

char *Math::Add(const char *str1, const char *str2) {
  int s3 = strlen(str1) + strlen(str2) + 1;
  char *a;
  a = (char *)malloc(s3);
  for (int i = 0; i < strlen(str1); i++) a[i] = str1[i];
  for (int i = 0; i < strlen(str2); i++) a[i + strlen(str1)] = str2[i];
  return a;
}