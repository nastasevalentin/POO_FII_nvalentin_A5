#include "Circuit.h"
class Dacia : public Car {
  float hours;

 public:
  Dacia();
  ~Dacia();

  float GetAverageSpeed(Weather weather);
  float GetFuelCapacity();
  float GetFuelConsumption(Weather weather);
  float GetHours(Weather weather);
  int GetTimeToFinish(Weather weather, int length);
  // const char* GetName() override { return "Dacia"; }
};