#include "Car.h"

class Mazda : public Car {
 public:
  Mazda() {
    fuelCapacity = 42;
    fuelConsumption = 9;
    averageSpeedSunny = 90;
    averagespeedRainy = 60;
    averageSpeedSnow = 60;
  }
};