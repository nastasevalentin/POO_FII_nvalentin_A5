#include "Car.h"
#include "Weather.h"

class Circuit {
 public:
  int l;

  void SetLength(int length);
  void SetWeather(Weather wheater);
  void AddCar(Car);
  // Car::weather SetWeather(Car::weather weather) { return weather; }
};
