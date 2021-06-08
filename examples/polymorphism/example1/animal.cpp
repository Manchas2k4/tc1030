/*************************************************************
* File: animal.cpp
* Author: Pedro Perez
* Description: This file contains the implementation of
*              Animal class and its derived classes (Fish,
*							 Shark).
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#include "animal.h"

/*************************************************************
* Implementation of Animal class
*************************************************************/
std::vector<Animal*> Animal::animals = std::vector<Animal*>();

Animal::Animal()
	: type(NONE), gPeriod(GPERIOD), currentCell(NULL),
	 	alive(true) {
}

Animal::Animal(AnimalType t, Cell *c)
	: type(t), gPeriod(GPERIOD), currentCell(c), alive(true) {
}

Animal::Animal(const Animal &a)
	: type(a.type), gPeriod(a.gPeriod), currentCell(a.currentCell),
	  alive(a.alive) {
}

AnimalType Animal::getAnimalType() const {
	return type;
}

uchar Animal::getGPeriod() const {
	return gPeriod;
}

Cell* Animal::getCurrentCell() const {
	return currentCell;
}

bool Animal::isAlive() const {
	return alive;
}

void Animal::setAnimalType(AnimalType t) {
	type = t;
}

void Animal::setGPeriod(uchar gp) {
	gPeriod = (gp > GPERIOD)? GPERIOD : gp;
}

void Animal::setCurrentCell(Cell* c) {
	currentCell = c;
}

void Animal::setAlive(bool a) {
	alive = a;
}

/*************************************************************
* Implementation of Animal class
*************************************************************/
Fish::Fish()
	: Animal(FISH, NULL) {
}

Fish::Fish(Cell *c)
	: Animal(FISH, c) {
}

Fish::Fish(const Fish &f)
	: Animal(FISH, f.currentCell) {
}

void Fish::move() {
	std::vector<Cell*> neighbors;
	Animal *child;
	Cell *next;
	int pos;

	if (!isAlive()) {
		return;
	}

	neighbors = currentCell->getNeighbors();

	pos = -1;
	for (int i = 0; i < neighbors.size(); i++) {
		if (neighbors[i]->getContent() == NULL ||
				!neighbors[i]->getContent()->isAlive()) {
			pos = i;
			break;
		}
	}

	if (pos != -1) {
		currentCell->setContent(NULL);

		if (gPeriod == 0) {
			child = new Fish(currentCell);
			currentCell->setContent(child);
			Animal::animals.push_back(child);
			gPeriod = GPERIOD;
		}

		currentCell = neighbors[pos];
		currentCell->setContent(this);
	}

	gPeriod--;
}

/*************************************************************
* Implementation of Shark class
*************************************************************/
Shark::Shark()
	: Animal(SHARK, NULL), sPeriod(SPERIOD) {
}

Shark::Shark(Cell *c)
	: Animal(SHARK, c), sPeriod(SPERIOD) {
}

Shark::Shark(const Shark &s)
	: Animal(SHARK, s.currentCell), sPeriod(s.sPeriod) {
}

uchar Shark::getSPeriod() const {
	return sPeriod;
}

void Shark::setSPeriod(uchar sp) {
	sPeriod = (sp > SPERIOD)? SPERIOD : sp;
}

void Shark::move() {
	std::vector<Cell*> neighbors;
	Animal *child, *food, *aux;
	Cell *next;
	int pos;

	if (!isAlive()) {
		return;
	}

	if (sPeriod == 0) {
		aux = currentCell->getContent();
		aux->setAlive(false);
		currentCell->setContent(NULL);
		return;
	}

	neighbors = currentCell->getNeighbors();

	pos = -1;
	for (int i = 0; i < neighbors.size(); i++) {
		if (neighbors[i]->getContent() != NULL &&
				neighbors[i]->getContent()->getAnimalType() == FISH) {
			pos = i;
			break;
		}
	}

	if (pos != -1) {
		food = neighbors[pos]->getContent();
		neighbors[pos]->setContent(NULL);
		food->setAlive(false);
		sPeriod = SPERIOD;
	}

	pos = -1;
	for (int i = 0; i < neighbors.size(); i++) {
		if (neighbors[i]->getContent() == NULL ||
				!neighbors[i]->getContent()->isAlive()) {
			pos = i;
			break;
		}
	}

	if (pos != -1) {
		currentCell->setContent(NULL);

		if (gPeriod == 0) {
			child = new Shark(currentCell);
			currentCell->setContent(child);
			Animal::animals.push_back(child);
			gPeriod = GPERIOD;
		}

		currentCell = neighbors[pos];
		currentCell->setContent(this);
	}

	gPeriod--;
	sPeriod--;
}
