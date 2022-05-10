#include "Weather.h"
class Ford : public Car {
 public:
  Ford();
  ~Ford();

  float GetAverageSpeed(Weather weather);
  float GetFuelCapacity();
  float GetFuelConsumption(Weather weather);
  float GetHours(Weather weather);
  int GetTimeToFinish(Weather weather, int length);
};