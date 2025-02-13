#ifndef BOOK_H
#define BOOK_H

#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

class Book {
private:
	int id;
	string title, author;
	float price;

public:
	Book();
	Book(int, string, string, float);
	Book(const Book &);

	int getId() const;
	string getTitle() const;
	string getAuthor() const;
	float getPrice() const;
	string toString() const;
};

Book::Book() 
	: id(-1), title("noname"), author("noname"), price(-1.0)
{}

Book::Book(int i, string t, string a, float p)
	:id(i), title(t), author(a), price(p)
{}

Book::Book(const Book &b) 
	: id(b.id), title(b.title), author(b.author), price(b.price) 
{}

int Book::getId() const {
	return id;
}

string Book::getTitle() const {
	return title;
}

string Book::getAuthor() const {
	return author;
}

float Book::getPrice() const {
	return price;
}

string Book::toString() const {
	stringstream salida;

	salida << "Id = " << id << ", Title: " << title 
		<< ", Author: " << author << ", Price: $" 
		<< fixed << setprecision(2) << price;
	return salida.str();
}

#endif