/*************************************************************
* File: ucatalog.h
* Author: Pedro Perez
* Description: This file contains the implementation of
*							 UserCatalog class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#include "ucatalog.h"

UserCatalog::UserCatalog() {
	limit = MAXSIZE;
	current = 0;
	users = new User*[limit];
}

UserCatalog::UserCatalog(uint m) {
	limit = m;
	current = 0;
	users = new User*[limit];
}

UserCatalog::UserCatalog(const UserCatalog &uc) {
	limit = uc.limit;
	current = uc.current;

	users = new User*[limit];
	for (int i = 0; i < current; i++) {
		users[i] = new User( (*uc.users[i]) );
	}
}

UserCatalog::~UserCatalog() {
	clear();
}

long UserCatalog::indexOf(uint id) const {
	long pos = -1;
	for (int i = 0; i < current; i++) {
		if (users[i]->getId() == id) {
			pos = i;
			break;
		}
	}
	return pos;
}

User* UserCatalog::getUserById(uint id) const {
	long pos;

	pos = indexOf(id);

	if (pos == -1) {
		return NULL;
	} else {
		return users[pos];
	}
}

bool UserCatalog::addUser(User *u) {
	long pos;
	User** newUsers;

	pos = indexOf(u->getId());

	if (pos != -1) {
		return false;
	}

	if (current == limit) {
		limit = limit + ((limit * 3) / 2);
		newUsers = new User*[limit];
		for (int i = 0; i < current; i++) {
			newUsers[i] = users[i];
		}
		delete [] users;
		users = newUsers;
	}
	users[current] = u;
	current++;
	return true;
}

bool UserCatalog::removeUserById(uint id) {
	long pos;

	pos = indexOf(id);

	if (pos == -1) {
		return false;
	}

	delete users[pos];
	for (int i = pos; i < (current - 1); i++) {
		users[i] = users[i + 1];
	}
	current--;
	return true;
}

bool UserCatalog::changeUser(User *u) {
	long pos;

	pos = indexOf(u->getId());

	if (pos == -1) {
		return false;
	}

	users[pos] = u;
	return true;
}

void UserCatalog::clear() {
	for (int i = 0; i < current; i++) {
		delete users[i];
	}
	delete [] users;
	users = NULL;
	limit = 0;
	current = 0;
}

bool UserCatalog::load(std::string filename) {
	std::ifstream file(filename);
	std::string input;

	if (!file.is_open()) {
		return false;
	}

	clear();
	file >> limit >> current;
	file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	users = new User*[limit];
	for (int i = 0; i < current; i++) {
		getline(file, input);
		users[i] = new User(input);
	}
	return true;
}

bool UserCatalog::save(std::string filename) const {
	std::ofstream file(filename);

	if (!file.is_open()) {
		return false;
	}

	file << limit << "\n" << current << "\n";
	for (int i = 0; i < current; i++) {
		file << users[i]->toString() << "\n";
	}
	return true;
}

std::string UserCatalog::toString() const {
	std::stringstream aux;

	aux << limit << "\n" << current << "\n";
	for (int i = 0; i < current; i++) {
		aux << users[i]->toString() << "\n";
	}
	return aux.str();
}
