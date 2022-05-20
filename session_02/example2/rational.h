// =========================================================
// File: rational.h
// Author:
// Date:
// Description:
// =========================================================
#ifndef RATIONAL_H
#define RATIONAL_H

// https://github.com/Manchas2k4/tc1030/
class Rational {
private:
  int numerator, denominator;

public:
  Rational();
  Rational(int);
  Rational(int, int);
  Rational(const Rational&);

  int getNumerator() const;
  int getDenominator() const;

  void setNumerator(int);
  void setDenominator(int);

  Rational add(const Rational&);
  Rational sub(const Rational&);
  Rational mult(const Rational&);
  Rational div(const Rational&);

  bool equals(const Rational&);
  bool less(const Rational&);
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
}

Rational::Rational(const Rational &right) {
  numerator = right.numerator;
  denominator = right.denominator;
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

Rational Rational::add(const Rational &right) {
  int num, den;

  den = denominator * right.denominator;
  num = (numerator * right.denominator) + (denominator * right.numerator);

  return Rational(num, den);
}

Rational Rational::sub(const Rational &right) {
  int num, den;

  den = denominator * right.denominator;
  num = (numerator * right.denominator) - (denominator * right.numerator);

  return Rational(num, den);
}

Rational Rational::mult(const Rational &right) {
  int num, den;

  num = numerator * right.numerator;
  den = denominator * right.denominator;

  return Rational(num, den);
}

Rational Rational::div(const Rational &right) {
  int num, den;

  num = numerator * right.denominator;
  den = denominator * right.numerator;

  return Rational(num, den);
}

bool Rational::equals(const Rational &right) {
  int a, b;

  a = numerator * right.denominator;
  b = denominator * right.numerator;

  return (a == b);
}

bool Rational::less(const Rational &right) {
  int a, b;

  a = numerator * right.denominator;
  b = denominator * right.numerator;

  return (a < b);
}
#endif
