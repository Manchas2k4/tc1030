/**
    File: Rational.h
    Purpose: This file contains the implementation of the Rational class

    @author Pedro Perez
    @version 2.0 13/01/2019
*/

#ifndef Rational_H_
#define Rational_H_

#include <string>
#include <sstream>

using namespace std;

class Rational {
private:
	int numerator;
	int denominator;

	int gcd(int, int) const;
	void normalize();

public:
	Rational();
	Rational(int);
	Rational(int, int);
	Rational(const Rational&);

	int getNumerator() const;
	int getDenominator() const;
	string toString() const;

	void operator=  (const Rational&);
	void operator+= (const Rational&);

	operator double () const;
};

/**
	Constructor by default of the class. 
*/
Rational::Rational() 
: numerator(0), denominator(1) {}

/**
	Constructor. Receives as a value the initial value of the 
	instance variable numerator
	
	@param num initial value of numerator
*/
Rational::Rational(int num) 
: numerator(num), denominator(1) {}

/**
	Constructor. Initializes both instance variables.
	
	@param num initial value of numerator.
	@param dem initial value of denominator.
*/
Rational::Rational(int num, int dem) 
: numerator(num), denominator(dem) {
	normalize();
}

/**
	Returns the current value the instance variable numerator.
	
	@return current value of numerator.
*/
int Rational::getNumerator() const {
	return numerator;
}

/**
	Returns the current value the instance variable denominator.
	
	@return current value of denominator.
*/
int Rational::getDenominator() const {
	return denominator;
}

/**
	Returns a string representation of the object.
	
	@return an string representation of the object.
*/
std::string Rational::toString() const {
	std::stringstream aux;

	aux << numerator << "/" << denominator;
	return aux.str();
}

/**
	Assigns new contents to the container, replacing its current contents.
*/
void Rational::operator= (const Rational &right) {
	numerator   = right.numerator;
	denominator = right.denominator;
}

/**
	Add content to the container, replacing its current contents.
*/
void Rational::operator+= (const Rational &right) {
	numerator    = (numerator * right.denominator) + (denominator * right.numerator);
	denominator *= right.denominator;
	normalize();
}

/**
	Returns a double representation of the object.
	
	@return double representation of the objetc.
*/
Rational::operator double () const {
	return numerator / (double) denominator;
}

/**
	Calculate the greatest common divisor of two integer values.
	
	@param a integer value.
	@param b integer value.
	@return  the greatest common divisor.
*/
int Rational::gcd(int a, int b) const {
	int aux;

	while (b != 0) {
		aux = b;
		b = a % b;
		a = aux;
	}
	return a;
}

/**
	Normalize Rational by: move sign to numerator, make sure numerator 
	and denominator have no common divisors.
*/
void Rational::normalize() {
	int sign = 1;
	if (numerator < 0) {
		sign = -1;
		numerator = -numerator;
	}
	if (denominator < 0) {
		sign = -sign;
		denominator = -denominator;
	}
	if (denominator == 0) {
		denominator = 1;
	}

	int d = gcd(numerator, denominator);

	numerator   = sign * (numerator / d);
	denominator = denominator / d;
}

/**
	Returns addition of two Rational numbers.
*/
Rational operator+ (const Rational &left, const Rational &right) {
	int num, dem;

	num = (left.getNumerator() * right.getDenominator()) + (left.getDenominator() * right.getNumerator());
	dem = left.getDenominator() * right.getDenominator();

	return Rational(num, dem);
}

/**
	Returns the difference of two Rational numbers.
*/
Rational operator- (const Rational &left, const Rational &right) {
	int num, dem;

	num = (left.getNumerator() * right.getDenominator()) - (left.getDenominator() * right.getNumerator());
	dem = left.getDenominator() * right.getDenominator();

	return Rational(num, dem);
}

/**
	Returns negation of a Rational number.
*/
Rational operator- (const Rational &right) {
	return Rational(-right.getNumerator(), right.getDenominator());
}

/**
	Returns true if left is equal than right
*/
bool operator== (const Rational &left, const Rational &right) {
	return (left.getNumerator() * right.getDenominator()) == (left.getDenominator() * right.getNumerator());
}

/**
	Returns true if left is less than right
*/
bool operator<  (const Rational &left, const Rational &right) {
	return (left.getNumerator() * right.getDenominator()) < (left.getDenominator() * right.getNumerator());
}

#endif /* Rational_H_ */
