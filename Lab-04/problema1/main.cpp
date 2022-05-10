#include <iostream>

#include "Sort.h"
using namespace std;

int main() { /*
   Sort v1("4,5,2,3");
   v1.BubbleSort(true);
   v1.Print();*/

  Sort v2(3, 2, 7, 3);
  v2.BubbleSort(true);
  v2.Print();

  Sort v3(new int[3]{5, 2, 9}, 3);
  v3.BubbleSort(true);
  v3.Print();

  Sort v4(4, 2, 9);
  v4.QuickSort(false);
  v4.Print();

  Sort v5(new int[3]{9, 5, 6}, 3);
  v5.InsertSort(false);
  v5.Print();

  cout << v5.GetElementFromIndex(2) << ' ' << v5.GetElementsCount();
  return 0;
}