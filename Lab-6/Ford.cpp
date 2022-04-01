#include "Ford.h"

#include "Circuit.h"
float Ford::GetFuelConsumption(Weather weather) {
  if (weather == Sunny) {
    return 0.1;
  }
  if (weather == Rainy) {
    return 0.15;
  }
  if (weather == Snow) {
    return 0.2;
  }
  return 0;
}

float Ford::GetAverageSpeed(Weather weather) {
  if (weather == Sunny) {
    return 90;
  }
  if (weather == Rainy) {
    return 70;
  }
  if (weather == Snow) {
    return 55;
  }
  return 0;
}

float Ford::GetFuelCapacity() { return 35; }
float Ford::GetHours(Weather weather) {
  return GetFuelCapacity() / GetFuelConsumption(weather);
}

int Ford::GetTimeToFinish(Weather weather, int length) {
  int hours_to_finish = length / GetAverageSpeed(weather);
}
