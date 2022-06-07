// =========================================================
// File: figure.h
// Author: Pedro O. Perez M.
// Date: 26-may-2022
// Description: This file contains the description and
//							implementation of the Figure class. This
//							class is the base of a hierarchy.
// =========================================================
#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

typedef enum {UNDEFINED, CIRCLE, SQUARE, RECTANGLE} Type;

class Figure {
protected:
	Type type;

public:
	Figure();
	Figure(Type t);
	Figure(const Figure&);
	Type getType() const;
	virtual double getArea() const = 0;
	virtual double getPerimeter() const = 0;
	virtual std::string toString() const;
};

Figure::Figure() {
	type = UNDEFINED;
}

Figure::Figure(Type t)
	: type(t) {
	// type = t;
}

Figure::Figure(const Figure &f) {
	type = f.type;
}

Type Figure::getType() const {
	return type;
}

std::string Figure::toString() const {
	std::stringstream aux;

	aux << "Perimeter = " << std::fixed << std::setprecision(4) << getPerimeter()
			<< " Area = " << getArea();
	return aux.str();
}
#endif
