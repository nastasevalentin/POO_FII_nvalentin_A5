#include "Toyota.h"

#include "Circuit.h"
float Toyota::GetFuelConsumption(Weather weather) {
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

float Toyota::GetAverageSpeed(Weather weather) {
  if (weather == Sunny) {
    return 85;
  }
  if (weather == Rainy) {
    return 65;
  }
  if (weather == Snow) {
    return 54;
  }
  return 0;
}

float Toyota::GetFuelCapacity() { return 50; }

float Toyota::GetHours(Weather weather) {
  return GetFuelCapacity() / GetFuelConsumption(weather);
}

int Toyota::GetTimeToFinish(Weather weather, int length) {
  int hours_to_finish = length / GetAverageSpeed(weather);
}
