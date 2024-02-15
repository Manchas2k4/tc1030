// =========================================================
// File: rational.h
// Author:
// Date:
// Description:
// =========================================================
#ifndef RATIONAL_H
#define RATIONAL_H

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

#endif
