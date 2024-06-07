// =========================================================
// File: circle.h
// Author: Pedro O. Perez M.
// Date: 26-may-2022
// Description: This file contains the description and
//							implementation of the Circle class. This
//							class represents a geometric figure of
//              the circle type.
// =========================================================
#ifndef CIRCLE_H
#define CIRCLE_H

#include "figure.h"

const double PI = 3.141592653589793238;

class Circle : public Figure {
protected:
	double radius;

public:
	Circle();
  Circle(double);
	Circle(const Circle&);
  double getRadius() const;
	double getArea() const;
	double getPerimeter() const;
	std::string toString() const;
};

Circle::Circle()
  : Figure(CIRCLE) {
	radius = 0;
}

Circle::Circle(double r)
  : Figure(CIRCLE) {
	radius = r;
}

Circle::Circle(const Circle &c)
  : Figure(c) {
	radius = c.radius;
}

double Circle::getRadius() const {
	return PI * radius * radius;
}

double Circle::getArea() const {
	return PI * radius * radius;
}

double Circle::getPerimeter() const {
	return 2 * PI * radius;
}

std::string Circle::toString() const {
	std::stringstream aux;

	aux <<"Type = CIRCLE " << Figure::toString();
	return aux.str();
}
#endif
