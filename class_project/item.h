/*************************************************************
* File: item.h
* Author: Pedro Perez
* Description: This file contains the definition of Item class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <sstream>
#include "types.h"

class Item {
protected:
	ItemType 	type;
	uint 			id;
	std::string		title;
	int				year;
	bool			borrowed;

public:
	Item();
	Item(ItemType, uint, std::string, int, bool);
	Item(const Item&);

	ItemType getType() const;
	uint getId() const;
	std::string getTitle() const;
	int getYear() const;
	bool isBorrowed() const;

	void setType(ItemType);
	void setId(uint);
	void setTitle(std::string);
	void setYear(int);
	void setBorrowed(bool);

	std::string toString() const;
};

#endif
