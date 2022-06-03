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

typedef enum {UNDEFINED, CIRCLE, SQUARE, RECTANGLE} Type;

class Figure {
protected:
	Type type;

public:
	Figure();
	Figure(Type t);
	Figure(const Figure&);
	Type getType() const;
	virtual double getArea() const;
	virtual double getPerimeter() const;
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

double Figure::getArea() const {
	return 0;
}

double Figure::getPerimeter() const {
	return 0;
}
#endif
