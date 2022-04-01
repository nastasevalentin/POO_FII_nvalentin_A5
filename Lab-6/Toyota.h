#include "Weather.h"
class Toyota : public Car {
 public:
  Toyota();
  ~Toyota();

  float GetAverageSpeed(Weather weather);
  float GetFuelCapacity();
  float GetFuelConsumption(Weather weather);
  float GetHours(Weather weather);
  int GetTimeToFinish(Weather weather, int length);
};