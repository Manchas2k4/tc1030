// =========================================================
// File: rational.h
// Author:
// Date:
// Description:
// =========================================================
#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <algorithm> 

using namespace std;

class Rational {
private:
  int numerator, denominator;

  void simplify();

public:
  Rational();
  Rational(int);
  Rational(int, int);
  Rational(const Rational&);

  int getNumerator() const;
  int getDenominator() const;

  void setNumerator(int);
  void setDenominator(int);

  Rational operator+(const Rational&) const;
  Rational operator-(const Rational&) const;
  Rational operator*(const Rational&) const;
  Rational operator/(const Rational&) const;

  bool operator==(const Rational&) const;
  bool operator<(const Rational&) const;
};

Rational::Rational() {
  numerator = 0;
  denominator = 1;
}

Rational::Rational(int num) {
  numerator = num;
  denominator = 1;
}

Rational::Rational(int num, int den) {
  numerator = num;
  denominator = den;
  simplify();
}

Rational::Rational(const Rational &right) {
  numerator = right.numerator;
  denominator = right.denominator;
}

void Rational::simplify() {
  int sign, divisor;
  
  sign = 1;
  if (numerator < 0) {
    numerator *= -1;
    sign *= -1;
  }

  if (denominator < 0) {
    denominator *= -1;
    sign *= -1;
  }

  divisor = __gcd(numerator, denominator);

  numerator = (numerator / divisor) * sign;
  denominator /= divisor;
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

void Rational::setDenominator(int den) {
  denominator = den;
}

Rational Rational::operator+(const Rational &right) const {
  int num, den;

  den = denominator * right.denominator;
  num = (numerator * right.denominator) + (denominator * right.numerator);

  return Rational(num, den);
}

Rational Rational::operator-(const Rational &right) const {
  int num, den;

  den = denominator * right.denominator;
  num = (numerator * right.denominator) - (denominator * right.numerator);

  return Rational(num, den);
}

Rational Rational::operator*(const Rational &right) const {
  int num, den;

  num = numerator * right.numerator;
  den = denominator * right.denominator;

  return Rational(num, den);
}

Rational Rational::operator/(const Rational &right) const {
  int num, den;

  num = numerator * right.denominator;
  den = denominator * right.numerator;

  return Rational(num, den);
}

bool Rational::operator==(const Rational &right) const {
  int a, b;

  a = numerator * right.denominator;
  b = denominator * right.numerator;

  return (a == b);
}

bool Rational::operator<(const Rational &right) const {
  int a, b;

  a = numerator * right.denominator;
  b = denominator * right.numerator;

  return (a < b);
}

ostream& operator<< (ostream& out, const Rational &r) {
  out << r.getNumerator() << "/" << r.getDenominator();
  return out;
}
#endif
