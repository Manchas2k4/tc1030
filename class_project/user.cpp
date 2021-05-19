/*************************************************************
* File: user.cpp
* Author: Pedro Perez
* Description: This file contains the implementation of User
*							 class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#include "user.h"

User::User()
  : id(0), name("noname"), amountBorrowedItems(0), fine(0.0) {
}

User::User(uint i, std::string n)
  : id(i), name(n), amountBorrowedItems(0), fine(0.0) {
}

User::User(uint i, std::string n, uint a, double f)
  : id(i), name(n), amountBorrowedItems(a), fine(f) {
}

User::User(const User &u)
  : id(u.id), name(u.name),
    amountBorrowedItems(u.amountBorrowedItems), fine(u.fine) {
}

uint User::getId() const {
  return id;
}

std::string User::getName() const {
  return name;
}

uint User::geAmountBorrowedItems() const {
  return amountBorrowedItems;
}

double User::getFine() const {
  return fine;
}

void User::setId(uint i) {
  id = i;
}

void User::setName(std::string n) {
  name = n;
}

void User::setAmountBorrowedItems(uint a) {
  amountBorrowedItems = a;
}

void User::setFine(double f) {
  fine = f;
}

std::string User::toString() const {
	std::stringstream aux;

	aux << id << "," << name << "," << amountBorrowedItems
      << "," << fine;
	return aux.str();
}
