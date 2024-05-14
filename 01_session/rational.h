#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

using namespace std;

class Rational {
private:
	int numerator, denominator;
	
	void simplify();
	
public:
	Rational();
	Rational(int);
	Rational(int, int);
	Rational(const Rational &);
	
	int getNumerator() const;
	int getDenominator() const;
	
	void setNumerator(int);
	void setDenominator(int);
	
	Rational add(const Rational&) const;
	Rational sub(const Rational&) const ;
	
	bool equal(const Rational&) const;
	bool lessThan(const Rational&) const;
	
	void display() const;
};

Rational::Rational() {
	numerator = 0;
	denominator = 1;
}

Rational::Rational(int num) {
	numerator = num;
	denominator = 1;
}

Rational::Rational(int num, int dem) 
	: numerator(num), denominator(dem) {
	simplify();
}

Rational::Rational(const Rational &a) 
	: numerator(a.numerator), 
	  denominator(a.denominator) {
}

void Rational::simplify() {
}

int Rational::getNumerator() const {
	return numerator;
}

int Rational::getDenominator() const {
	return denominator;
}

void Rational::setNumerator(int num) {
	numerator = num;
}

void Rational::setDenominator(int dem) {
	denominator = dem;
}

Rational Rational::add(const Rational &a) const {
	int num = (numerator * a.denominator) +
	          (denominator * a.numerator);
	int dem = (denominator * a.denominator);
	return Rational(num, dem);
}

Rational Rational::sub(const Rational &a) const {
	int num = (numerator * a.denominator) -
	          (denominator * a.numerator);
	int dem = (denominator * a.denominator);
	return Rational(num, dem);
}

bool Rational::equal(const Rational &a) const {
	return (numerator * a.denominator) == 
		   (denominator * a.numerator);
}
	
bool Rational::lessThan(const Rational &a) const {
	return (numerator * a.denominator) < 
		   (denominator * a.numerator);
}	

void Rational::display() const {
	cout << numerator << "\\" << denominator;
}

#endif
