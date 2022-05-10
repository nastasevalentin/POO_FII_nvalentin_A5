#pragma once
#include <stdio.h>

#include "Circuit.h"
#include "Weather.h"
class Car {
  // Car() { printf("A new car has been created\n"); }
  //~Car() { printf("A car has been destroyed\n"); }

 public:
  virtual int GetTimeToFinish(Weather weather, int length) = 0;
  virtual const char* GetName() = 0;
  virtual float GetFuelConsumption(Weather weather) = 0;
  virtual float GetFuelCapacity() = 0;
  virtual float GetAverageSpeed(Weather weather) = 0;
};