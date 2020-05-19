#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

class Rectangle : public Figure {
protected:
	float base, height;

public:
	Rectangle();
	Rectangle(float b, float h);
	float getBase() const;
	float getHeight() const;
	void setBase(float b);
	void setHeight(float h);
	float getArea() const;
	float getPerimeter() const; 
};

Rectangle::Rectangle() 
	: Figure("rectangle"), base(0), height(0) {
}

Rectangle::Rectangle(float b, float h) 
	: Figure("rectangle"), base(b), height(h) {	
}

float Rectangle::getBase() const {
	return base;
}

float Rectangle::getHeight() const {
	return height;
}

void Rectangle::setBase(float b) {
	base = b;
}

void Rectangle::setHeight(float h) {
	height = h;
}

float Rectangle::getArea() const {
	return (base * height);
}

float Rectangle::getPerimeter() const {
	return (2 * base) + (2 * height);
}
#endif