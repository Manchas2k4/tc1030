// =========================================================
// File: square.h
// Author: Pedro O. Perez M.
// Date: 26-may-2022
// Description: This file contains the description and
//							implementation of the Square class. This
//							class represents a geometric figure of
//              the square type.
// =========================================================
#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"

class Square : public Figure {
protected:
	double side;

public:
	Square();
	Square(double);
	Square(const Square&);
	double getSide() const;
	void setSide(double b);
	double getArea() const;
	double getPerimeter() const;
};

Square::Square()
	: Figure(SQUARE), side(0) {
}

Square::Square(double s)
	: Figure(SQUARE), side(s) {
}

Square::Square(const Square &r)
	: Figure(r), side(r.side) {
}

double Square::getSide() const {
	return side;
}

void Square::setSide(double s) {
	side = s;
}

double Square::getArea() const {
	return (side * side);
}

double Square::getPerimeter() const {
	return (4 * side);
}

#endif
