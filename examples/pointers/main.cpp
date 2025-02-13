#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include "book.h"
#include "category.h"

using namespace std;

// 0-Adventure, 1-Fantasy, 2-Scifi, 3-Police, 4-Mistery
const int CATEGORIES = 5; 
const int SIZE = 100;

int counter = 0;
vector<Book> books(SIZE);
vector<Category> categories(CATEGORIES);

int convertToInt(string name) {
	if (name == "Adventure") {
		return 0;
	} else if (name == "Fantasy") {
		return 1;
	} else if (name == "Scifi") {
		return 2;
	} else if (name == "Police") {
		return 3;
	} else if (name == "Mistery") {
		return 4;
	} else {
		return -1;
	}
}

bool loadFile(string name) {
	ifstream file(name);
	string title, author, category;
	int size, amount;
	float price;

	if (!file) {
		return false;
	}

	file >> size; file.ignore();
	for (int i = 0; i < size; i++) {
		getline(file, title);
		getline(file, author);
		file >> price; file.ignore();

		books[i] = Book(i, title, author, price);

		file >> amount; 
		for (int j = 0; j < amount; j++) {
			file >> category;
			categories[convertToInt(category)].addBook(&books[i]);
		}
		file.ignore();

		counter++;
	}
	return true;
}

void addABook() {
	string title, author;
	float price;

	cout << "Title? ";
	getline(cin, title);
	cout << "Author? ";
	getline(cin, author);
	cout << "Price? ";
	cin >> price;

	books[counter] = Book(counter, title, author, price);
	cout << books[counter].toString() << "\n";

	counter++;
}

void displayTheBooks() {
	for (int i = 0; i < counter; i++) {
		cout << books[i].toString() << "\n";
	}
}

void displayCategory() {
	int categoryId;

	cout << "0. Adventure\n";
	cout << "1. Fantasy\n";
	cout << "2. Scifi\n";
	cout << "3. Police\n";
	cout << "4. Mistery\n";
	cout << "What categories are you going to modify? ";
	cin >> categoryId;

	cout << categories[categoryId].toString();
}

void addBookToCategory() {
	int id, categoryId;

	cout << "0. Adventure\n";
	cout << "1. Fantasy\n";
	cout << "2. Scifi\n";
	cout << "3. Police\n";
	cout << "4. Mistery\n";
	cout << "What categories are you going to modify? ";
	cin >> categoryId;

	displayTheBooks();
	cout << "Which book do you want to add? ";
	cin >> id;

	categories[categoryId].addBook(&books[id]);
}

void deleteBookFromCategory() {
	int id, categoryId;

	cout << "0. Adventure\n";
	cout << "1. Fantasy\n";
	cout << "2. Scifi\n";
	cout << "3. Police\n";
	cout << "4. Mistery\n";
	cout << "What categories are you going to modify? ";
	cin >> categoryId;

	cout << categories[categoryId].toString();
	cout << "Which book do you want to delete? ";
	cin >> id;

	categories[categoryId].deleteBook(id);
}

int main(int argc, char* argv[]) {
	int option;

	for (int i = 0; i < categories.size(); i++) {
		categories[i] = Category(i);
	}

	if (!loadFile("catalog.txt")) {
		return -1;
	}

	do { 
		cin.clear();
		
		cout << "1. Add a new Book\n";
		cout << "2. Display all book\n";
		cout << "3. Display all books from a category\n";
		cout << "4. Add a Book to a Category\n";
		cout << "5. Add a Book to a Category\n";
		cout << "6. Exit\n";
		cout << "What do you want to do? ";
		cin >> option;

		switch (option) {
			case 1 : addABook(); break;
			case 2 : cout << "Catalog:\n"; displayTheBooks(); break;
			case 3 : displayCategory(); break;
			case 4 : addBookToCategory();
			case 5 : deleteBookFromCategory();
		}
	} while (option != 6);

	return 0;
}