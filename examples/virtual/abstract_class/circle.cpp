/*************************************************************
* File: circle.cpp
* Author: Pedro Perez
* Description: This file contains the implementation of
*              Circle class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#include "circle.h"

Circle::Circle() 
	: radio(1) {
}

Circle::Circle(double r) 
	: radio(r) {
}

Circle::Circle(const Circle &c)
	: radio(c.radio) {
}

double Circle::getRadio() const {
	return radio;
}

void Circle::setRadio(double r) {
	radio = r;
}

double Circle::perimeter() const {
	return 2 * PI * radio;
}

double Circle::area() const {
	return PI * radio * radio;
}