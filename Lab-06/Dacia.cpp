#include "Dacia.h"

#include "Circuit.h"
float Dacia::GetFuelConsumption(Weather weather) {
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

float Dacia::GetAverageSpeed(Weather weather) {
  if (weather == Sunny) {
    return 80;
  }
  if (weather == Rainy) {
    return 65;
  }
  if (weather == Snow) {
    return 50;
  }
  return 0;
}

float Dacia::GetFuelCapacity() { return 30; }

float Dacia::GetHours(Weather weather) {
  return GetFuelCapacity() / GetFuelConsumption(weather);
}

int Dacia::GetTimeToFinish(Weather weather, int length) {
  int hours_to_finish = length / GetAverageSpeed(weather);
}
