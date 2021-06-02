/*************************************************************
* File: cell.cpp
* Author: Pedro Perez
* Description: This file contains the implementation of
*              Cell class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#include "cell.h"

Cell::Cell() {
	content = NULL;
	for (int i = 0; i < 4; i++) {
		neighbors[i] = NULL;
	}
}

Cell::Cell(Cell *north, Cell *east, Cell *south, Cell *west) {
	content = NULL;
	neighbors[0] = north;
	neighbors[1] = east;
	neighbors[2] = south;
	neighbors[3] = west;
}

Cell::Cell(const Cell &c) {
	content = c.content;
	for (int i = 0; i < 4; i++) {
		neighbors[i] = c.neighbors[i];
	}
}

Animal* Cell::getContent() const {
	return content;
}

void Cell::setContent(Animal *a) {
	content = a;
}

std::vector<Cell*> Cell::getNeighbors() const {
	std::vector<Cell*> cells;
	for (int i = 0; i < 4; i++) {
		if (neighbors[i] != NULL) {
			cells.push_back(neighbors[i]);
		}
	}
	return cells;
}
