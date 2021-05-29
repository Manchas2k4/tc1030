/*************************************************************
* File: book.h
* Author: Pedro Perez
* Description: This file contains the definition of Book class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#ifndef BOOK_H
#define BOOK_H

#include "item.h"

class Book : public Item {
private:
	std::string writer;

public:
	Book();
	Book(uint, std::string, std::string, int, bool);
	Book(std::string);
	Book(const Book&);

	std::string getWriter() const;

	void setWriter(std::string);

	std::string toString() const;
};

#endif
