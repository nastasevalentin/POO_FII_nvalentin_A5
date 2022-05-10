#include "Weather.h"

class Mazda : public Car {
 public:
  Mazda();
  ~Mazda();

  float GetAverageSpeed(Weather weather);
  float GetFuelCapacity();
  float GetFuelConsumption(Weather weather);
  float GetHours(Weather weather);
  int GetTimeToFinish(Weather weather, int length);
};