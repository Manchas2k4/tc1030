/*************************************************************
* File: scroll.cpp
* Author: Pedro Perez
* Description: This file contains the implementation of Scroll
*							 class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#include "scroll.h"

Scroll::Scroll()
	: Item(SCROLL), month(1) {
}

Scroll::Scroll(uint i, std::string t, uchar m, int y, bool b)
	: Item(SCROLL, i, t, y, b), month(m) {
}

Scroll::Scroll(std::string line) {
	std::vector<std::string> result;

	result = split(line);
	type = SCROLL;
	id = (uint) stol(result[1]);
  title = result[2];
	month = (uchar) stoi(result[3]);
	year = stoi(result[4]);
	borrowed = (bool) stoi(result[5]);
}

Scroll::Scroll(const Scroll &s)
	: Item(s.type, s.id, s.title, s.year, s.borrowed),
		month(s.month) {
}

uchar Scroll::getMonth() const {
	return month;
}

void Scroll::setMonth(uchar m) {
	month = m;
}

std::string Scroll::toString() const {
	std::stringstream aux;

	aux << type << "," << id << "," << title << "," << month
			<< "," << year << "," << borrowed;
	return aux.str();
}
