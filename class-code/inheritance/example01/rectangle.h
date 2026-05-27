// =========================================================
// File: rectangle.h
// Author: Pedro O. Perez M.
// Date: 26-may-2022
// Description: This file contains the description and
//							implementation of the Rectangle class. This
//							class represents a geometric figure of
//              the rectangle type.
// =========================================================
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

class Rectangle : public Figure {
protected:
	double base, height;

public:
	Rectangle();
	Rectangle(double, double);
	Rectangle(const Rectangle&);
	double getBase() const;
	double getHeight() const;
	void setBase(double b);
	void setHeight(double h);
	double getArea() const;
	double getPerimeter() const;
	std::string toString() const;
};

Rectangle::Rectangle()
	: Figure(RECTANGLE), base(0), height(0) {
}

Rectangle::Rectangle(double b, double h)
	: Figure(RECTANGLE), base(b), height(h) {
}

Rectangle::Rectangle(const Rectangle &r)
	: Figure(r), base(r.base), height(r.height) {
}

double Rectangle::getBase() const {
	return base;
}

double Rectangle::getHeight() const {
	return height;
}

void Rectangle::setBase(double b) {
	base = b;
}

void Rectangle::setHeight(double h) {
	height = h;
}

double Rectangle::getArea() const {
	return (base * height);
}

double Rectangle::getPerimeter() const {
	return (2 * base) + (2 * height);
}

std::string Rectangle::toString() const {
	std::stringstream aux;

	aux <<"Type = RECTANGLE " << Figure::toString();
	return aux.str();
}
#endif
