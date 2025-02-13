#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "user.h"

using namespace std;

const int SIZE = 100;

int counter = 0;
vector<User> users(SIZE);

bool loadFile(string filename) {
	ifstream file(filename);
	string name, friends;
	int id1, id2, size, amount;

	if (!file) {
		return false;
	}

	file >> size; file.ignore();
	for (int i = 0; i < size; i++) {
		file >> id1;
		getline(file, name);
		cout << "id = " << id1 << " name = " << name << "\n";
		users[id1] = User(id1, name);
		counter = max(counter, id1);
	}

	for (int i = 0; i < size; i++) {
		file >> id1 >> amount;
		cout << "id1 = " << id1 << " amount = " << amount << "\n";
		for (int j = 0; j < amount; j++) {
			file >> id2;
			cout << "id2 = " << id2 << "\n";
			users[id1].addFriend(&users[id2]);
		}
	}

	counter++;

	return true;
}

void displayUsers() {
	for (int i = 0; i < counter; i++) {
		cout << users[i].toString() << "\n";
	}
}

void addAUser() {
	string name;
	
	cout << "Name? ";
	getline(cin, name);
	
	users[counter] = User(counter, name);
	cout << users[counter].toString() << "\n";

	counter++;
}

void addFriendToUser() {
	int id1, id2;

	displayUsers();
	cout << "Which user do you want to add a friend to? ";
	cin >> id1;

	displayUsers();
	cout << "Which user do you want to add as a friend? ";
	cin >> id2;

	if (id1 != id2) {
		users[id1].addFriend(&users[id2]);
	}
}

void deleteFriendFromUser() {
	int id1, id2;

	displayUsers();
	cout << "Which user do you want to unfriend? ";
	cin >> id1;

	displayUsers();
	cout << "Which user do you want to unfriend? ";
	cin >> id2;

	if (id1 != id2) {
		users[id1].deleteFriend(&users[id2]);
	}
}

int main(int argc, char* argv[]) {
	int option;

	if (!loadFile("users.txt")) {
		return -1;
	}

	do { 
		cin.clear();
		
		cout << "1. Add a new User\n";
		cout << "2. Display all users\n";
		cout << "3. Add a new Friend to a User\n";
		cout << "4. Remove a Friend from a User\n";
		cout << "5. Exit\n";
		cout << "What do you want to do? ";
		cin >> option;
		
		cin.ignore();

		switch (option) {
			case 1 : addAUser(); break;
			case 2 : cout << "Users:\n"; displayUsers(); break;
			case 3 : addFriendToUser(); break;
			case 4 : deleteFriendFromUser(); break;
		}
	} while (option != 5);

	return 0;
}