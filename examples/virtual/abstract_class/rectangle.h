/*************************************************************
* File: rectangle.h
* Author: Pedro Perez
* Description: This file contains the definition of
*              Rectangle class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

class Rectangle : public Figure {
private:
	double width, height;

public:
	Rectangle();
	Rectangle(double, double);
	Rectangle(const Rectangle&);

	double getWidth() const;
	double getHeight() const;

	void setWidth(double);
	void setHeight(double);

	double perimeter() const;
	double area() const;
};

#endif