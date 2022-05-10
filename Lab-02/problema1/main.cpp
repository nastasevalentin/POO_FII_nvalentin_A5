#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <iostream>

#include "NumberList.h"

using namespace std;

int main() {
  int x;
  NumberList n;
  n.Init();
  printf("Introdu numarul de numere: ");
  {
    cin >> x;
    while (n.Add(x)) {
      cin >> x;
    }
  }
  n.Sort();
  n.Print();
}