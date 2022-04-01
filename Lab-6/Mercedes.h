#include "Weather.h"
class Mercedes : public Car {
 public:
  Mercedes();
  ~Mercedes();

  float GetAverageSpeed(Weather weather);
  float GetFuelCapacity();
  float GetFuelConsumption(Weather weather);
  float GetHours(Weather weather);
  int GetTimeToFinish(Weather weather, int length);
};