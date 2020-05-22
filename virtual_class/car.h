#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Car {
protected:
	string pilot;
	int distance;
	int totalDistance;

public:
	Car();
	Car(string p, int total);
	Car(const Car &c);
	/*
	string getPilot() const;
	int getDistance() const;
	int getTotalDistance() const;
	*/

	void goStartingPoint();
	bool reachTheEnd() const;
	string toString() const;
	virtual void move() = 0;
};

Car::Car() 
	: pilot("noname"), distance(0), totalDistance(0) {
}

Car::Car(string p, int total)  
	: pilot(p), distance(0), totalDistance(total) {
}

Car::Car(const Car & c)
	: pilot(c.pilot),  distance(c.distance), totalDistance(c.totalDistance) {
}

void Car::goStartingPoint() {
	distance = 0;
}

bool Car::reachTheEnd() const {
	return (distance >= totalDistance);
}

string Car::toString() const {
	stringstream aux;

	aux << "Pilot = " << pilot << " distance = " << distance 
			<< " total = " << totalDistance;
	return aux.str();
}

#endif