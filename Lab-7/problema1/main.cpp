#include <iostream>
using namespace std;

long double operator"" _Kelvin(unsigned long long x) { return x + 273.15; }

long double operator"" _Fahrenheit(unsigned long long x) {
  return x * 1.8 + 32;
}

int main() {
  float a = 300_Kelvin;
  float b = 120_Fahrenheit;
  cout << a << ' ' << b;
  return 0;
}