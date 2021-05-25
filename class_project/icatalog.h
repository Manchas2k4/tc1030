/*************************************************************
* File: icatalog.h
* Author: Pedro Perez
* Description: This file contains the definition of
*              ItemCatalog class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/

#ifndef BCATALOG_H
#define BCATALOG_H

#include "utils.h"
#include "item.h"

class ItemCatalog {
private:
	Item** items;
	uint current, limit;

	long indexOf(uint) const;

public:
	ItemCatalog();
	ItemCatalog(uint);
	ItemCatalog(const ItemCatalog&);

	~ItemCatalog();

	Item* getItemById(uint) const;
	bool addItem(Item*);
	bool removeItemById(uint);
	bool changeUser(Item*);

	void clear();
	bool load(std::string);
	bool save(std::string) const;

	std::string toString() const;
};

#endif
