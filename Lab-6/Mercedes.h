#include "Car.h"
class Mercedes : public Car {
 public:
  Mercedes() {
    fuelCapacity = 50;
    fuelConsumption = 7;
    averageSpeedSunny = 110;
    averagespeedRainy = 70;
    averageSpeedSnow = 70;
  }
};