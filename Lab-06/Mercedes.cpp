#include "Mercedes.h"

#include "Circuit.h"
float Mercedes::GetFuelConsumption(Weather weather) {
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

float Mercedes::GetAverageSpeed(Weather weather) {
  if (weather == Sunny) {
    return 100;
  }
  if (weather == Rainy) {
    return 75;
  }
  if (weather == Snow) {
    return 65;
  }
  return 0;
}

float Mercedes::GetFuelCapacity() { return 60; }

float Mercedes::GetHours(Weather weather) {
  return GetFuelCapacity() / GetFuelConsumption(weather);
}

int Mercedes::GetTimeToFinish(Weather weather, int length) {
  int hours_to_finish = length / GetAverageSpeed(weather);
}