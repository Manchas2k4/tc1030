/*************************************************************
* File: user.h
* Author: Pedro Perez
* Description: This file contains the definition of
*              BorrowedCatalog class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/

#ifndef BCATALOG_H
#define BCATALOG_H

#include "utils.h"
#include "borrowed.h"

class BorrowedCatalog {
private:
	BorrowedItem** items;
	uint current, limit;

	long indexByUserId(uint) const;
  long indexByItemId(uint) const;

public:
	BorrowedCatalog();
	BorrowedCatalog(uint);
	BorrowedCatalog(const BorrowedCatalog&);

	~BorrowedCatalog();

	BorrowedItem** getBorrowedItemsByUserId(uint) const;
  BorrowedItem*  getBorrowedItemByItemId(uint) const;
	bool addBorrowedItem(BorrowedItem*);
	bool removeBorrowedItemByUserId(uint);
  bool removeBorrowedItemByItemId(uint);
	bool changeBorrowedItem(BorrowedItem*);

	void clear();
	bool load(std::string);
	bool save(std::string) const;

	std::string toString() const;
};

#endif
