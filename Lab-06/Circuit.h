#pragma once
#include "Car.h"
#include "Weather.h"
class Circuit {
 private:
  int max_carCount = 10;
  Car** cars;
  int length = 0;
  int carCount = 0;
  Weather weather;

 public:
  Circuit();
  ~Circuit();
  void SetLength(int len);
  void SetWeather(Weather weather);
  void AddCar(Car* car);
  void Race();
  void ShowFinalRanks();
  void ShowWhoDidNotFinish();
  // Car::weather SetWeather(Car::weather weather) { return weather; }
};
