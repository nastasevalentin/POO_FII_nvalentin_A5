#include "Car.h"

class Dacia : public Car {
 public:
  Dacia() {
    fuelCapacity = 50;
    fuelConsumption = 9;
    averageSpeedSunny = 80;
    averagespeedRainy = 50;
    averageSpeedSnow = 50;
  }
};