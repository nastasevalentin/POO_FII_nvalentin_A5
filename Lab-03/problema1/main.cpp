#include <iostream>

#include "Math.h"
using namespace std;
int main() {
  cout << Math::Add(1, 2) << endl;
  cout << Math::Add(1, 2, 3) << endl;
  cout << Math::Add(1.0, 2.0) << endl;
  cout << Math::Add(1.0, 2.0, 3.0) << endl;

  cout << Math::Mul(4, 7) << endl;
  cout << Math::Mul(4, 7, 9) << endl;
  cout << Math::Mul(4.0, 7.0) << endl;
  cout << Math::Mul(4.0, 7.0, 9.0) << endl;

  cout << Math::Add(4, 3, 5, 8, 4) << endl;
  cout << Math::Add("Hello", " world!") << endl;
}
