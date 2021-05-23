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
	max = MAX;
	current = 0;
	users = new User*[max];
}

UserCatalog::UserCatalog(uint m) {
	max = m;
	current = 0;
	users = new User*[max];
}

UserCatalog::UserCatalog(const UserCatalog &uc) {
	max = uc.max;
	current = uc.current;

	users = new User*[max];
	for (int i = 0; i < current; i++) {
		users[i] = new User( (*uc.users[i]) );
	}
}

UserCatalog::~UserCatalog() {
	for (int i = 0; i < current; i++) {
		delete users[i];
	}
	delete [] users;
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

void UserCatalog::addUser(User *u) {
	long pos;

	pos = indexOf(u->getId());

	if (pos == -1) {
		users[current] = u;
		current++;
	}
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

bool changeUser(User*);

bool UserCatalog::load(std::string filename) {
	std::ifstream file(filename);
	std::string input;

	if (!file.is_open()) {
		return false;
	}

	file >> max;
	file >> current;

	users = new User*[max];
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

	file << max << "\n";
	file << current << "\n";
	for (int i = 0; i < current; i++) {
		file << users[i]->toString() << "\n";
	}
	return true;
}
