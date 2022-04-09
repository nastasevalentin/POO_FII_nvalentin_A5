#include <iostream>

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

  v.sort();
  for (int i = 0; i < v.countV(); i++) {
    printf("%d ", v.get(i));
  }
}