/*************************************************************
* File: fraction.h
* Author: Pedro Perez
* Description: This file contains the definition of
*              Fraction class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
private:
	int numerator, denominator;

public:
	Fraction();
	Fraction(int);
	Fraction(int, int);
	Fraction(const Fraction&);

	int getNumerator() const;
	int getDenominator() const;

	void operator= (const Fraction&);
};

Fraction operator+ (const Fraction&, const Fraction&);
Fraction operator+ (int, const Fraction&);
Fraction operator+ (const Fraction&, int);
bool operator> (const Fraction&, const Fraction&);
std::ostream& operator<< (std::ostream&, const Fraction&);
#endif