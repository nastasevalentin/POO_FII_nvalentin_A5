#include "NumberList.h"

#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <iostream>
using namespace std;

//<tipuldereturn> <nume_clasa>::<nume_metoda> (parametri daca sunt)
//{<implementarea>}
// ca sa accesam atribute ale clasei folosim ->

void NumberList::Init() { this->count = 0; }

bool NumberList::Add(int x) {
  // if (this->count >= 10) return false;
  numbers[this->count] = x;
  this->count++;

  if (this->count == 10) return false;
  return true;
}

void NumberList::Sort() {
  for (int i = 0; i < 9; i++)
    for (int j = i + 1; j < 10; j++) {
      if (this->numbers[i] > this->numbers[j])
        swap(this->numbers[i], this->numbers[j]);
    }
}

void NumberList::Print() {
  printf("Sirul ordonat este:\n");
  for (int i = 0; i <= 9; i++) printf(" %d ", this->numbers[i]);
}
