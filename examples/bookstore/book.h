// =================================================================
//
// File: Book.h
// Author: Pedro Perez
// Description: This file contains the implementation of the Book 
// class.
//
// Copyright (c) 2025 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//
// =================================================================

#ifndef BOOK_H
#define BOOK_H

#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

// =================================================================
// Definition of the Book class
// =================================================================
class Book {
private:
	int id;
	string title, author;
	float price;

public:
	Book();
	Book(const Book &);
	Book(int, string, string, float);

	int getId() const;
	string getTitle() const;
	string getAuthor() const;
	float getPrice() const;
	string toString() const;
};

// =================================================================
// Default constructor. Initializes instance variables with "empty" 
// values.
// =================================================================
Book::Book() 
	: id(-1), title("noname"), author("noname"), price(-1.0)
{}

// =================================================================
// Copy constructor.
//
// @param b, the object to be copied.
// =================================================================
Book::Book(const Book &b) 
	: id(b.id), title(b.title), author(b.author), price(b.price) 
{}

// =================================================================
// Constructor. Initializes Initializes instance variables with 
// values ​​received as parameters.
//
// @param i, identifier.
// @param t, title.
// @param a, author name.
// @param p, price.
// =================================================================
Book::Book(int i, string t, string a, float p)
	:id(i), title(t), author(a), price(p)
{}

// =================================================================
// Returns the identifier of the book.
//
// @returns int, the identifier of the book.
// =================================================================
int Book::getId() const {
	return id;
}

// =================================================================
// Returns the tittle of the book.
//
// @returns string, the title of the book.
// =================================================================
string Book::getTitle() const {
	return title;
}

// =================================================================
// Returns the author name of the book.
//
// @returns string, the author name of the book.
// =================================================================
string Book::getAuthor() const {
	return author;
}

// =================================================================
// Returns the price of the book.
//
// @returns float, the price of the book.
// =================================================================
float Book::getPrice() const {
	return price;
}


// =================================================================
// Returns a string containing all the information about the object.
//
// @returns string, the object information.
// =================================================================
string Book::toString() const {
	stringstream salida;

	salida << "Id = " << id << ", Title: " << title 
		<< ", Author: " << author << ", Price: $" 
		<< fixed << setprecision(2) << price;
	return salida.str();
}

#endif