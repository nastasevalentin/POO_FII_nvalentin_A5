#include "Circuit.h"

#include <iostream>
using namespace std;

void Circuit::SetLength(int length) { this->length = length; }

void Circuit::SetWeather(Weather weather) { this->weather = weather; }

void Circuit::AddCar(Car* car) {
  this->carCount++;
  this->cars = (Car**)realloc(this->cars, this->carCount * sizeof(Car*));
  this->cars[this->carCount - 1] = car;
}
Circuit::Circuit() : weather(Sunny), length(100) {
  this->cars = (Car**)calloc(1, sizeof(Car*));
  this->carCount = 0;
};

Circuit::~Circuit() { free(this->cars); };

void Circuit::Race() {
  for (int i = 0; i < this->carCount; i++) {
    for (int j = 0; j < this->carCount; j++) {
      if (this->cars[i]->GetTimeToFinish(this->weather, this->length) <
          this->cars[j]->GetTimeToFinish(this->weather, this->length)) {
        std::swap(this->cars[i], this->cars[j]);
      }
    }
  }
}

void Circuit::ShowFinalRanks() {
  for (int i = 0; i < this->carCount; i++) {
    int time = this->cars[i]->GetTimeToFinish(this->weather, this->length);

    if (time > 0) {
      printf("%s finished in %d hours\n", this->cars[i]->GetName(), time);
    }
  }
}

void Circuit::ShowWhoDidNotFinish() {
  for (int i = 0; i < this->carCount; i++) {
    if (this->cars[i]->GetTimeToFinish(this->weather, this->length) == 0) {
      printf("%s did not finish\n", this->cars[i]->GetName());
    }
  }
}