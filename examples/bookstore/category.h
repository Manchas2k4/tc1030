// =================================================================
//
// File: Category.h
// Author: Pedro Perez
// Description: This file contains the implementation of the 
// Category class.
//
// Copyright (c) 2025 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//
// =================================================================

#ifndef CATEGORY_H
#define CATEGORY_H

#include <iomanip>
#include <sstream>
#include <string>
#include <list>
#include <algorithm> 
#include "book.h"

using namespace std;

// =================================================================
// Definition of the Book class
// =================================================================
class Category {
private:
	int id;
	list<Book*> books;

public:
	Category();
	Category(const Category&);
	Category(int);

	string getName() const;
	
	bool addBook(Book*);
	bool deleteBook(int);
	string toString() const;
};

// =================================================================
// Default constructor. 
// =================================================================
Category::Category() {
}

// =================================================================
// Copy constructor.
//
// @param b, the object to be copied.
// =================================================================
Category::Category(const Category &c)
	: id(c.id), books(c.books) {
}

// =================================================================
// Constructor. Initializes Initializes instance variables with 
// values ​​received as parameters.
//
// @param i, identifier.
// =================================================================
Category::Category(int i)
	: id(i) {
}

// =================================================================
// Returns the category name.
//
// @returns string, the category name.
// =================================================================
string Category::getName() const {
	switch (id) {
		case 0	: return "Adventure";
		case 1	: return "Fantasy";
		case 2	: return "Scifi";
		case 3	: return "Police";
		case 4	: return "Mistery";
		default	: return "Sin nombre";
	}
}

// =================================================================
// Adds a book reference to the list of books belonging to this 
// category.
//
// @param b, the book reference to add.
// @returns bool, Returns true if the object is valid (not null) and 
//				  has not been previously added.
// =================================================================
bool Category::addBook(Book* b) {
	list<Book*>::iterator itr;
	if (b != NULL) {
		itr = find(books.begin(), books.end(), b);
		if (itr == books.end()) {
			books.push_back(b);
			return true;
		}
	}
	return false;
}

// =================================================================
// Removes the reference to the book with a given identifier from 
// the list of books belonging to this category.
//
// @param b, the book reference to remove.
// @returns bool, Returns true if there is a reference that has the 
//				  id that is received as a parameter.
// =================================================================
bool Category::deleteBook(int id) {
	list<Book*>::iterator itr;

	for (itr = books.begin(); itr != books.end(); itr++) {
		if ((*itr)->getId() == id) {
			books.erase(itr);
			return true;
		}
	}
	return false;
}

// =================================================================
// Returns a string containing all the information about the object.
//
// @returns string, the object information.
// =================================================================
string Category::toString() const {
	stringstream salida;

	salida << getName() << ":\n";
	for (Book* b : books) {
		salida << b->toString() << "\n";
	}
	return salida.str();
}

#endif