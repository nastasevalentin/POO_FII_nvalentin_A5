#include <iostream>

#include "Canvas.h"
using namespace std;

int main() {
  Canvas tabla(40, 30);
  tabla.DrawCircle(15, 30, 5, '#');
  tabla.Print();
  tabla.Clear();
  tabla.FillCircle(15, 30, 5, '#');
  tabla.Print();
  tabla.Clear();
  tabla.DrawRect(10, 10, 25, 25, '#');
  tabla.Print();
  tabla.Clear();
  tabla.FillRect(10, 10, 25, 25, '#');
  tabla.Print();
  tabla.Clear();
  tabla.DrawLine(10, 10, 25, 25, '#');
  tabla.Print();
}