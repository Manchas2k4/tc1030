#ifndef RACE_H
#define RACE_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "car.h"

using namespace std;

const int LOW = 5;
const int HIGH = 8;

class RaceCar : public Car {
public:
	RaceCar();
	RaceCar(string p, int total);

	void move();
};

RaceCar::RaceCar() 
	: Car() {
}

RaceCar::RaceCar(string p, int total) 
	: Car(p, total) {
}

//low...high =>(x mod (high - low + 1)) + low

void RaceCar::move() {
	distance += (rand() % (HIGH - LOW + 1)) + LOW;
}

#endif