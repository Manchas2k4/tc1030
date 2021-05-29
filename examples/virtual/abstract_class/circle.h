/*************************************************************
* File: circle.h
* Author: Pedro Perez
* Description: This file contains the definition of
*              Circle class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#ifndef CIRCLE_H
#define CIRCLE_H

#include "figure.h"

#define PI 3.14159265358979323846

class Circle : public Figure {
private:
	double radio;

public:
	Circle();
	Circle(double);
	Circle(const Circle&);

	double getRadio() const;

	void setRadio(double);

	double perimeter() const;
	double area() const;
};

#endif