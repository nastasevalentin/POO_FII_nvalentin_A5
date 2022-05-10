#include "Mazda.h"

#include "Circuit.h"
float Mazda::GetFuelConsumption(Weather weather) {
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

float Mazda::GetAverageSpeed(Weather weather) {
  if (weather == Sunny) {
    return 93;
  }
  if (weather == Rainy) {
    return 75;
  }
  if (weather == Snow) {
    return 57;
  }
  return 0;
}

float Mazda::GetFuelCapacity() { return 35; }

float Mazda::GetHours(Weather weather) {
  return GetFuelCapacity() / GetFuelConsumption(weather);
}

int Mazda::GetTimeToFinish(Weather weather, int length) {
  int hours_to_finish = length / GetAverageSpeed(weather);
}