#include "Car.h"

class Toyota : public Car {
 public:
  Toyota() {
    fuelCapacity = 42;
    fuelConsumption = 8;
    averageSpeedSunny = 90;
    averagespeedRainy = 50;
    averageSpeedSnow = 50;
  }
};