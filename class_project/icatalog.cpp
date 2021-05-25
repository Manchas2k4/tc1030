/*************************************************************
* File: icatalog.cpp
* Author: Pedro Perez
* Description: This file contains the implementation of
*							 ItemCatalog class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#include "icatalog.h"

ItemCatalog::ItemCatalog() {
	limit = MAXSIZE;
	current = 0;
	items = new Item*[limit];
}

ItemCatalog::ItemCatalog(uint m) {
	limit = m;
	current = 0;
	items = new Item*[limit];
}

ItemCatalog::ItemCatalog(const ItemCatalog &ic) {
	limit = ic.limit;
	current = ic.current;

	items = new Item*[limit];
	for (int i = 0; i < current; i++) {
		items[i] = new Item( (*ic.items[i]) );
	}
}

ItemCatalog::~ItemCatalog() {
	clear();
}

long ItemCatalog::indexOf(uint id) const {
	long pos = -1;
	for (int i = 0; i < current; i++) {
		if (items[i]->getId() == id) {
			pos = i;
			break;
		}
	}
	return pos;
}

Item* ItemCatalog::getItemById(uint id) const {
	long pos;

	pos = indexOf(id);

	if (pos == -1) {
		return NULL;
	} else {
		return items[pos];
	}
}

bool ItemCatalog::addItem(Item *i) {
	long pos;
	Item** newItems;

	pos = indexOf(i->getId());

	if (pos != -1) {
		return false;
	}

	if (current == limit) {
		limit = limit + ((limit * 3) / 2);
		newItems = new Item*[limit];
		for (int i = 0; i < current; i++) {
			newItems[i] = items[i];
		}
		delete [] items;
		items = newItems;
	}
	items[current] = i;
	current++;
	return true;
}

bool ItemCatalog::removeItemById(uint id) {
	long pos;

	pos = indexOf(id);

	if (pos == -1) {
		return false;
	}

	delete items[pos];
	for (int i = pos; i < (current - 1); i++) {
		items[i] = items[i + 1];
	}
	current--;
	return true;
}

bool ItemCatalog::changeUser(Item *i) {
	long pos;

	pos = indexOf(i->getId());

	if (pos == -1) {
		return false;
	}

	items[pos] = i;
	return true;
}

void ItemCatalog::clear() {
	for (int i = 0; i < current; i++) {
		delete items[i];
	}
	delete [] items;
	items = NULL;
	limit = 0;
	current = 0;
}

bool ItemCatalog::load(std::string filename) {
	std::ifstream file(filename);
	std::string input;

	if (!file.is_open()) {
		return false;
	}

	clear();
	file >> limit >> current;
	file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	items = new Item*[limit];
	for (int i = 0; i < current; i++) {
		getline(file, input);
		items[i] = new Item(input);
	}
	return true;
}

bool ItemCatalog::save(std::string filename) const {
	std::ofstream file(filename);

	if (!file.is_open()) {
		return false;
	}

	file << limit << "\n" << current << "\n";
	for (int i = 0; i < current; i++) {
		file << items[i]->toString() << "\n";
	}
	return true;
}

std::string ItemCatalog::toString() const {
	std::stringstream aux;

	aux << limit << "\n" << current << "\n";
	for (int i = 0; i < current; i++) {
		aux << items[i]->toString() << "\n";
	}
	return aux.str();
}
