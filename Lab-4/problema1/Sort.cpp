#include "Sort.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include <cstring>
#include <iostream>
using namespace std;

Sort::Sort(char* string) {
  char s[100], *P;
  int cnt = 0;
  v = new int[strlen(string)];
  P = strtok(string, ",");
  while (P != NULL) {
    int x = 0;
    strcpy(s, P);
    for (int i = 0; i < strlen(s); i++) x = x * 10 + (s[i] - '0');
    v[cnt++] = x;
    P = strtok(NULL, ",");
  }
}

Sort::Sort(int count, ...) {
  va_list vl;
  va_start(vl, count);
  for (int i = 0; i < count; i++) {
    v[i] = va_arg(vl, int);
  }
  va_end(vl);
  n = count;
}

Sort::Sort(int* vector, int nrel) {
  v = new int[nrel];
  for (int i = 0; i < nrel; i++) v[i] = vector[i];
}

Sort::Sort(int nr_of_elements, int minx, int maxx) {
  time_t t;
  this->n = nr_of_elements;
  v = new int[nr_of_elements];
  srand((unsigned)time(&t));
  for (int i = 0; i < nr_of_elements; i++)
    v[i] = minx + rand() % (maxx - minx + 1);
}

Sort::Sort() : v(new int[4]{1, 2, 3, 4}) { n = 6; }

void Sort::InsertSort(bool ascendent) {
  int key;
  if (ascendent) {
    for (int i = 0; i < n; i++) {
      key = v[i];
      int j = i - 1;
      while (j >= 0 && v[j] > key) {
        v[j + 1] = v[j];
        j--;
      }
      v[j + 1] = key;
    }
  } else {
    for (int i = 0; i < n; i++) {
      key = v[i];
      int j = i - 1;
      while (j >= 0 && v[j] < key) {
        v[j + 1] = v[j];
        j--;
      }
      v[j + 1] = key;
    }
  }
}

int Sort::qsort_part(bool ascendent, int low, int high) {
  int pivot = this->v[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {
    if (ascendent ? this->v[j] < pivot : this->v[j] > pivot) {
      i++;
      swap(this->v[i], this->v[j]);
    }
  }

  swap(this->v[i + 1], this->v[high]);
  return (i + 1);
}

void Sort::qsort_rec(bool ascendent, int low, int high) {
  if (low < high) {
    int pi = qsort_part(ascendent, low, high);

    qsort_rec(ascendent, low, pi - 1);
    qsort_rec(ascendent, pi + 1, high);
  }
}

void Sort::QuickSort(bool ascendent) { qsort_rec(ascendent, 0, this->n - 1); }

void Sort::BubbleSort(bool ascendent) {
  int i, j;

  for (i = 0; i < this->n - 1; i++) {
    for (j = 0; j < this->n - i - 1; j++) {
      if (ascendent ? this->v[j] > this->v[j + 1]
                    : this->v[j] < this->v[j + 1]) {
        swap(this->v[j], this->v[j + 1]);
      }
    }
  }
}

void Sort::Print() {
  cout << n;
  for (int i = 0; i < n; i++) cout << v[i] << ' ';
}

int Sort::GetElementsCount() {
  int count = 0;
  for (int i = 0; i < n; i++) count++;
  return count;
}

int Sort::GetElementFromIndex(int index) { return v[index]; }