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
	// TO DO
	return false;
}

void displayUsers() {
	// TO DO
}

void addAUser() {
	string name;
	
	cout << "Name? ";
	getline(cin, name);
	
	// TO DO
}

void addFriendToUser() {
	int id1, id2;

	displayUsers();
	cout << "Which user do you want to add a friend to? ";
	cin >> id1;

	displayUsers();
	cout << "Which user do you want to add as a friend? ";
	cin >> id2;

	// TO DO
}

void deleteFriendFromUser() {
	int id1, id2;

	displayUsers();
	cout << "Which user do you want to unfriend? ";
	cin >> id1;

	displayUsers();
	cout << "Which user do you want to unfriend? ";
	cin >> id2;

	// TO DO
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