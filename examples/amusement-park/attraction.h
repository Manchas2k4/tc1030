// =================================================================
//
// File: Category.h
// Author: Pedro Perez
// Description: This file contains the implementation of the classes
// Attraction, RollerCoaster, HouseOfHorror, BumperCars.
//
// Copyright (c) 2025 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//
// =================================================================
#ifndef ATTRACTION_H
#define ATTRACTION_H

#include <string>
#include <random>
#include <sstream>
#include <iostream>

using namespace std;

// =================================================================
// Definition of the Attraction class
// =================================================================
class Attraction {
protected:
	int id;
	string name;

public:
	Attraction();
	Attraction(const Attraction&);
	Attraction(int, string);

	int getId() const;
	string getName() const;
	
	virtual string toString() const;

    virtual int calculateFun() const = 0;

	bool operator<(const Attraction&) const;
	bool operator==(const Attraction&) const;
	friend ostream& operator<<(ostream&, const Attraction&);
};

// =================================================================
// Default constructor. 
// =================================================================
Attraction::Attraction()
	: id(-1), name("noname") {
}

// =================================================================
// Copy constructor.
//
// @param b, the object to be copied.
// =================================================================
Attraction::Attraction(const Attraction &a)
	: id(a.id), name(a.name) {
}

// =================================================================
// Constructor. Initializes Initializes instance variables with 
// values ​​received as parameters.
//
// @param i, identifier.
// @param n, name of the attraction.
// =================================================================
Attraction::Attraction(int i, string n)
	: id(i), name(n) {
}

// =================================================================
// Returns the id of the attraction.
//
// @returns int, the id of the attraction.
// =================================================================
int Attraction::getId() const {
	return id;
}

// =================================================================
// Returns the name of the attraction.
//
// @returns string, the name of the attraction.
// =================================================================
string Attraction::getName() const {
	return name;
}

// =================================================================
// Returns a string containing all the information about the object.
//
// @returns string, the object information.
// =================================================================
string Attraction::toString() const {
	stringstream salida;
	salida << "Name = " << name;
	return salida.str();
}

// =================================================================
// Compares the base attraction(this) with another attraction.
//
// @returns bool, returns true if the base attraction generates less 
//				  fun than the other attraction.
// =================================================================
bool Attraction::operator<(const Attraction &other) const {
	return (this->calculateFun() < other.calculateFun());
}


// =================================================================
// Compares the base attraction(this) with another attraction.
//
// @returns bool, returns true if the base attraction's id is equal 
//				  to the other attraction's id.
// =================================================================
bool Attraction::operator==(const Attraction &other) const {
	return (this->getId() == other.getId());
}


// =================================================================
// Overloads the << operator to work with this class (and its 
// derivatives).
//
// @returns ostream&, the output stream object.
// =================================================================
ostream& operator<<(ostream &out, const Attraction &a) {
	out << a.toString();
	return out;
}

// =================================================================
// Definition of the RollerCoaster class
// =================================================================
class RollerCoaster : public Attraction {
private: 
	int speed;

public: 
	RollerCoaster();
	RollerCoaster(const RollerCoaster&);
	RollerCoaster(int, string, int);

	string toString() const;
	int calculateFun() const;
};

// =================================================================
// Default constructor. 
// =================================================================
RollerCoaster::RollerCoaster()
	: Attraction(), speed(0) {
}

// =================================================================
// Copy constructor.
//
// @param b, the object to be copied.
// =================================================================
RollerCoaster::RollerCoaster(const RollerCoaster &r)
	: Attraction(r), speed(r.speed) {
}

// =================================================================
// Constructor. Initializes Initializes instance variables with 
// values ​​received as parameters.
//
// @param i, identifier.
// @param n, name of the attraction.
// @param s, speed of the roller coaster.
// =================================================================
RollerCoaster::RollerCoaster(int i, string n, int s) 
	: Attraction(i, n), speed(s) {
}

// =================================================================
// Returns a string containing all the information about the object.
//
// @returns string, the object information.
// =================================================================
string RollerCoaster::toString() const {
	stringstream salida;
	salida << "Type = Roller Coaster " << Attraction::toString() 
		   << " Speed = " << speed;
	return salida.str();
}

// =================================================================
// Calculate the fun generated by this attraction.
//
// @returns int, the fun generated.
// =================================================================
int RollerCoaster::calculateFun() const {
	default_random_engine generator;
    uniform_int_distribution<int> distribution(5, 15);

	return (speed * 2) + distribution(generator);
}

// =================================================================
// Definition of the HouseOfHorror class
// =================================================================
class HouseOfHorror : public Attraction {
private: 
	int levelOfFear;

public: 
	HouseOfHorror();
	HouseOfHorror(const HouseOfHorror&);
	HouseOfHorror(int, string, int);

	string toString() const;
	int calculateFun() const;
};

// =================================================================
// Default constructor. 
// =================================================================
HouseOfHorror::HouseOfHorror()
	: Attraction(), levelOfFear(0) {
}

// =================================================================
// Copy constructor.
//
// @param b, the object to be copied.
// =================================================================
HouseOfHorror::HouseOfHorror(const HouseOfHorror &h)
	: Attraction(h), levelOfFear(h.levelOfFear) {
}

// =================================================================
// Constructor. Initializes Initializes instance variables with 
// values ​​received as parameters.
//
// @param i, identifier.
// @param n, name of the attraction.
// @param l, level of fear.
// =================================================================
HouseOfHorror::HouseOfHorror(int i, string n, int l) 
	: Attraction(i, n), levelOfFear(l) {
}

// =================================================================
// Returns a string containing all the information about the object.
//
// @returns string, the object information.
// =================================================================
string HouseOfHorror::toString() const {
	stringstream salida;
	salida << "Type = House of Horror " << Attraction::toString() 
		   << " Level of Fear = " << levelOfFear;
	return salida.str();
}

// =================================================================
// Calculate the fun generated by this attraction.
//
// @returns int, the fun generated.
// =================================================================
int HouseOfHorror::calculateFun() const {
	default_random_engine generator;
    uniform_int_distribution<int> distribution(10, 20);

	return (levelOfFear * 3) + distribution(generator);
}

// =================================================================
// Definition of the BumperCars class
// =================================================================
class BumperCars : public Attraction {
private: 
	int numberOfCars;

public: 
	BumperCars();
	BumperCars(const BumperCars&);
	BumperCars(int, string, int);

	string toString() const;
	int calculateFun() const;
};

// =================================================================
// Default constructor. 
// =================================================================
BumperCars::BumperCars()
	: Attraction(), numberOfCars(0) {
}

// =================================================================
// Copy constructor.
//
// @param b, the object to be copied.
// =================================================================
BumperCars::BumperCars(const BumperCars &b)
	: Attraction(b), numberOfCars(b.numberOfCars) {
}

// =================================================================
// Constructor. Initializes Initializes instance variables with 
// values ​​received as parameters.
//
// @param i, identifier.
// @param n, name of the attraction.
// @param c, number of cars.
// =================================================================
BumperCars::BumperCars(int i, string n, int c) 
	: Attraction(i, n), numberOfCars(c) {
}

// =================================================================
// Returns a string containing all the information about the object.
//
// @returns string, the object information.
// =================================================================
string BumperCars::toString() const {
	stringstream salida;
	salida << "Type = Bumper Cars " << Attraction::toString() 
			<< " Number of Cars = " << numberOfCars;
	return salida.str();
}

// =================================================================
// Calculate the fun generated by this attraction.
//
// @returns int, the fun generated.
// =================================================================
int BumperCars::calculateFun() const {
	default_random_engine generator;
	uniform_int_distribution<int> distribution(1, 5);

	return numberOfCars + distribution(generator);
}

#endif 