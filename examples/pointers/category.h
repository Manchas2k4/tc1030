#ifndef CATEGORY_H
#define CATEGORY_H

#include <iomanip>
#include <sstream>
#include <string>
#include <list>
#include <algorithm> 
#include "book.h"

using namespace std;

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

Category::Category() {
}

Category::Category(const Category &c)
	: id(c.id), books(c.books) {
}

Category::Category(int i)
	: id(i) {
}

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

string Category::toString() const {
	stringstream salida;

	salida << getName() << ":\n";
	for (Book* b : books) {
		salida << b->toString() << "\n";
	}
	return salida.str();
}

#endif