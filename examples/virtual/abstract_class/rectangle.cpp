/*************************************************************
* File: rectangle.cpp
* Author: Pedro Perez
* Description: This file contains the implementation of
*              Rectangle class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#include "rectangle.h"

Rectangle::Rectangle() 
	: width(1), height(2) {
}

Rectangle::Rectangle(double w, double h) 
	: width(w), height(h) {
}

Rectangle::Rectangle(const Rectangle &r)
	: width(r.width), height(r.height) {
}

double Rectangle::getWidth() const {
	return width;
}

double Rectangle::getHeight() const {
	return height;
}

void Rectangle::setWidth(double w) {
	width = w;
}

void Rectangle::setHeight(double h) {
	height = h;
}

double Rectangle::perimeter() const {
	return (2 * width) + (2 * height);
}

double Rectangle::area() const {
	return width * height;
}