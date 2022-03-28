#include "Car.h"
class Ford : public Car {
 public:
  Ford() {
    fuelCapacity = 55;
    fuelConsumption = 7;
    averageSpeedSunny = 95;
    averagespeedRainy = 60;
    averageSpeedSnow = 60;
  }
};