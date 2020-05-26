#ifndef TUNED_H
#define TUNED_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "car.h"

using namespace std;

// BASE: return weight * cost;

// TwoDay: return Package::calculateCost() + rate;

// Overnight: return Package::calculateCost() + (weight * rateAd);

class TunedCar : public Car {
private:
	int nitros;

public:
	TunedCar();
	TunedCar(string p, int total);

	void move();
};

TunedCar::TunedCar()
	: Car(), nitros(3) {
}

TunedCar::TunedCar(string p, int total) 
	: Car(p, total), nitros(3) {
}

void TunedCar::move() {
	distance += 2;
	// if (!nitros && !(rand % 2)) 
	if (nitros > 0 && rand() % 2 == 0) {
		distance += 10;
		nitros--;
	}
}
#endif