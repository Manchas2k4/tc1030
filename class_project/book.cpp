/*************************************************************
* File: book.cpp
* Author: Pedro Perez
* Description: This file contains the implementation of Book
*							 class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#include "book.h"

Book::Book()
	: Item(BOOK), writer("none") {
}

Book::Book(uint i, std::string t, std::string w, int y, bool b)
	: Item(BOOK, i, t, y, b), writer(w) {
}

Book::Book(std::string line) {
	std::vector<std::string> result;

	result = split(line);
	type = BOOK;
	id = (uint) stol(result[1]);
  title = result[2];
	writer = result[3];
	year = stoi(result[4]);
	borrowed = (bool) stoi(result[5]);
}

Book::Book(const Book &b)
	: Item(b.type, b.id, b.title, b.year, b.borrowed), writer(b.writer) {
}

std::string Book::getWriter() const {
	return writer;
}

void Book::setWriter(std::string w) {
	writer = w;
}

std::string Book::toString() const {
	std::stringstream aux;

	aux << type << "," << id << "," << title << "," << writer << "," << year
			<< "," << borrowed;
	return aux.str();
}
