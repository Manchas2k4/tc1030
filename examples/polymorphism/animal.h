/*************************************************************
* File: animal.h
* Author: Pedro Perez
* Description: This file contains the definition of
*              Animal class and its derived classes (Fish,
*							 Shark).
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <vector>
#include "cell.h"

#define GPERIOD	3
#define SPERIOD 3

typedef enum {NONE, FISH, SHARK} AnimalType;
typedef unsigned char uchar;

class Animal {
protected:
	AnimalType	type;
	uchar 			gPeriod;
	Cell*				currentCell;
	bool				alive;

public:
	Animal();
	Animal(AnimalType, Cell*);
	Animal(const Animal&);

	AnimalType getAnimalType() const;
	uchar getGPeriod() const;
	Cell* getCurrentCell() const;
	bool isAlive() const;

	void setAnimalType(AnimalType);
	void setGPeriod(uchar);
	void setCurrentCell(Cell*);
	void setAlive(bool);

	virtual void move() = 0;

	static std::vector<Animal*> animals;
};

class Fish : public Animal {
public:
	Fish();
	Fish(Cell*);
	Fish(const Fish&);

	void move();
};

class Shark : public Animal {
private:
	uchar sPeriod;

public:
	Shark();
	Shark(Cell*);
	Shark(const Shark&);

	uchar getSPeriod() const;

	void setSPeriod(uchar);

	void move();
};

#endif
