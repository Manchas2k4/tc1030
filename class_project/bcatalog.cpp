/*************************************************************
* File: bcatalog.h
* Author: Pedro Perez
* Description: This file contains the implementation of
*							 BorrowedCatalog class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#include "bcatalog.h"

BorrowedCatalog::BorrowedCatalog() {
	limit = MAXSIZE;
	current = 0;
	items = new BorrowedItem*[limit];
}

BorrowedCatalog::BorrowedCatalog(uint m) {
	limit = m;
	current = 0;
	items = new BorrowedItem*[limit];
}

BorrowedCatalog::BorrowedCatalog(const BorrowedCatalog &bc) {
	limit = bc.limit;
	current = bc.current;

	items = new BorrowedItem*[limit];
	for (int i = 0; i < current; i++) {
		items[i] = new BorrowedItem( (*bc.items[i]) );
	}
}

BorrowedCatalog::~BorrowedCatalog() {
	clear();
}

long BorrowedCatalog::indexByUserId(uint id) const {
	long pos = -1;
	for (int i = 0; i < current; i++) {
		if (items[i]->getUserId() == id) {
			pos = i;
			break;
		}
	}
	return pos;
}

long BorrowedCatalog::indexByItemId(uint id) const {
	long pos = -1;
	for (int i = 0; i < current; i++) {
		if (items[i]->getItemId() == id) {
			pos = i;
			break;
		}
	}
	return pos;
}

BorrowedItem** BorrowedCatalog::
							getBorrowedItemsByUserId(uint id) const {
  int count;
  BorrowedItem** result;

  count = 0;
  for (int i = 0; i < current; i++) {
    if (items[i]->getUserId() == id) {
      count++;
    }
  }

  if (count == 0) {
    return NULL;
  }

  result = new BorrowedItem*[count];
  for (int i = 0; i < current; i++) {
    if (items[i]->getUserId() == id) {
      result[i] = items[i];
    }
  }
  return result;
}

BorrowedItem*  BorrowedCatalog::
							getBorrowedItemByItemId(uint id) const {
	long pos;

	pos = indexByItemId(id);

	if (pos == -1) {
		return NULL;
	} else {
		return items[pos];
	}
}

bool BorrowedCatalog::addBorrowedItem(BorrowedItem *b) {
	long pos;
	BorrowedItem** newItems;

	pos = indexByItemId(b->getItemId());

	if (pos != -1) {
		return false;
	}

	if (current == limit) {
		limit = limit + ((limit * 3) / 2);
		newItems = new BorrowedItem*[limit];
		for (int i = 0; i < current; i++) {
			newItems[i] = items[i];
		}
		delete [] items;
		items = newItems;
	}
	items[current] = b;
	current++;
	return true;
}

bool BorrowedCatalog::removeBorrowedItemByUserId(uint id) {
	long pos;
	int i;

	i = 0;
	while (i < current) {
		if (items[i]->getUserId() == id) {
			delete items[i];
			for (int j = i; j < (current - 1); j++) {
				items[i] = items[i + 1];
			}
		} else {
			i++;
		}
	}

	current--;
	return true;
}

bool BorrowedCatalog::removeBorrowedItemByItemId(uint id) {
	long pos;

	pos = indexByItemId(id);

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


bool BorrowedCatalog::changeBorrowedItem(BorrowedItem *b) {
	long pos;

	pos = indexByItemId(b->getItemId());

	if (pos == -1) {
		return false;
	}

	items[pos] = b;
	return true;
}

void BorrowedCatalog::clear() {
	for (int i = 0; i < current; i++) {
		delete items[i];
	}
	delete [] items;
	items = NULL;
	limit = 0;
	current = 0;
}

bool BorrowedCatalog::load(std::string filename) {
	std::ifstream file(filename);
	std::string input;

	if (!file.is_open()) {
		return false;
	}

	clear();
	file >> limit >> current;
	file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	items = new BorrowedItem*[limit];
	for (int i = 0; i < current; i++) {
		getline(file, input);
		items[i] = new BorrowedItem(input);
	}
	return true;
}

bool BorrowedCatalog::save(std::string filename) const {
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

std::string BorrowedCatalog::toString() const {
	std::stringstream aux;

	aux << limit << "\n" << current << "\n";
	for (int i = 0; i < current; i++) {
		aux << items[i]->toString() << "\n";
	}
	return aux.str();
}
