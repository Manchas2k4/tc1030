/*************************************************************
* File: cell.h
* Author: Pedro Perez
* Description: This file contains the definition of
*              Cell class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#ifndef CELL_H
#define CELL_H

#include <cstdlib>
#include <vector>

class Animal;

// 0 - NORTH, 1 - EAST, 2 - SOUTH, 3 - WEST
class Cell {
private:
	Animal* content;
	Cell* 	neighbors[4];

public:
	Cell();
	Cell(Cell*, Cell*, Cell*, Cell*);
	Cell(const Cell&);

	Animal*	getContent() const;
	std::vector<Cell*> 	getNeighbors() const;

	void setContent(Animal*);
};
#endif
