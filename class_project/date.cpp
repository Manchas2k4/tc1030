/*************************************************************
* File: date.cpp
* Author: Pedro Perez
* Description: This file contains the implementation of Date
*							 class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#include "date.h"

Date::Date()
	: day(1), month(1), year(1) {
}

Date::Date(uchar d, uchar m, int y) {
	year = checkYear(y);
	month = checkMonth(m);
	day = checkDay(d);
}

Date::Date(const Date &date)
	: day(date.day), month(date.month), year(date.year) {
}

Date::Date(std::string line) {
	std::vector<std::string> result;

	result = split(line, '/');
  day = (uchar) stoi(result[0]);
  month = (uchar) stoi(result[1]);
  year = stoi(result[2]);
}

uchar Date::checkDay(uchar d) const {
	uchar limit;

	if (month == 1 || month == 3 || month == 5 || month == 7 ||
			month == 8 || month == 10 || month == 12) {
		limit = 31;
	} else if (month == 4 || month == 6 || month == 9 ||
						 month == 11) {
		limit = 30;
	} else {
		if (year % 100 == 0 && year % 400 == 0) {
			limit = 29;
		} else {
			limit = 28;
		}
	}

	return (d >= 1 && d <= limit)? d : 1;
}

uchar Date::checkMonth(uchar m) const {
	return (m >= 1 && m <= 12)? m : 1;
}

int Date::checkYear(int y) const {
	/*
	if (y != 0) {
		year = y;
	} else {
		year = 1;
	}

	year = (y != 0)? calculaAlgo(1, 3) : otroMetodo(59);
	*/
	return (y != 0)? y : 1;
}

uchar Date::getDay() const {
	return day;
}

uchar Date::getMonth() const {
	return month;
}

int Date::getYear() const {
	return year;
}

void Date::setDay(uchar d) {
	day = checkDay(d);
}

void Date::setMonth(uchar m) {
	month = checkMonth(m);
	day = checkDay(day);
}

void Date::setYear(int y) {
	year = checkYear(y);
	day = checkDay(day);
}

std::string Date::toString() const {
	std::stringstream aux;

	aux << std::setw(2) << std::setfill('0') << (int) day << "/"
			<< std::setw(2) << std::setfill('0') << (int) month << "/"
			<< std::setw(4) << std::setfill('0') << year;
	return aux.str();
}
