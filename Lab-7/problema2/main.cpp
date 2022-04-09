#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <memory>

#include "vector.h"
using namespace std;
int main() {
  Vector<int> v;

  v.push(5);
  v.push(8);
  v.push(3);

  v.remove(1);
  v.insert(1, 7);
  v.set(1, 2);
  cout << "Elementul de pe indicele 2 este: " << v.get(2) << '\n';
  cout << "Numarul de elemente este: " << v.countV() << '\n';
}