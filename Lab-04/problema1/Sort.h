#include <stdarg.h>
#include <time.h>
class Sort

{
  // add data members
  int n;
  int* v;

 public:
  // add constuctors
  Sort(int nr_of_elements, int min, int max);
  Sort(int a[], int nr);
  Sort(int count, ...);
  Sort(char* string);
  Sort();
  void InsertSort(bool ascendent = false);
  void QuickSort(bool ascendent = false);
  int qsort_part(bool ascendent, int low, int high);
  void qsort_rec(bool ascendent, int low, int high);
  void BubbleSort(bool ascendent = false);
  void Print();
  int GetElementsCount();
  int GetElementFromIndex(int index);
};