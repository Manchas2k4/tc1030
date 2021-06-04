/*************************************************************
* File: fraction.cpp
* Author: Pedro Perez
* Description: This file contains the implementation of
*              Fraction class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#include "fraction.h"

Fraction::Fraction() 
	: numerator(0), denominator(1) {
}

Fraction::Fraction(int n) 
	: numerator(n), denominator(1) {
}

Fraction::Fraction(int n, int d) 
	: numerator(n), denominator(d) {
}

Fraction::Fraction(const Fraction &f)
	: numerator(f.numerator), denominator(f.denominator) {
}

int Fraction::getNumerator() const {
	return numerator;
}

int Fraction::getDenominator() const {
	return denominator;
}

void Fraction::operator= (const Fraction &f) {
	numerator = f.numerator;
	denominator = f.denominator;
}

Fraction operator+ (const Fraction &left, const Fraction &right){
	int num = (left.getNumerator() * right.getDenominator()) + 
					  (left.getDenominator() * right.getNumerator());
	int dem = left.getDenominator() * right.getDenominator();
	return Fraction(num, dem);
}

Fraction operator+ (int num, const Fraction &right){
	Fraction left(num);
	return (left + right);
}

Fraction operator+ (const Fraction &left, int num){
	Fraction right(num);
	return (left + right);
}

bool operator> (const Fraction &left, const Fraction &right) {
	return (left.getNumerator() * right.getDenominator()) >
				 (left.getDenominator() * right.getNumerator());
}

std::ostream& operator<< (std::ostream &out, const Fraction &f) {
	out << f.getNumerator() << "/" << f.getDenominator();
	return out; 
}