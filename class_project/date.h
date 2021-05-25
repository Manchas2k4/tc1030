/*************************************************************
* File: date.h
* Author: Pedro Perez
* Description: This file contains the definition of Date class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#ifndef DATE_H
#define DATE_H

#include "utils.h"

class Date {
private:
	uchar day, month;
	int year;

	uchar checkDay(uchar) const;
	uchar checkMonth(uchar) const;
	int checkYear(int) const;

public:
	Date();
	Date(uchar, uchar, int);
	Date(std::string);
	Date(const Date&);

	uchar getDay() const;
	uchar getMonth() const;
	int	getYear() const;

	void setDay(uchar);
	void setMonth(uchar);
	void setYear(int);

	std::string toString() const;
};

#endif
