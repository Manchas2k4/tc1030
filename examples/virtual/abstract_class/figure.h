/*************************************************************
* File: figure.h
* Author: Pedro Perez
* Description: This file contains the definition of
*              Figure class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

class Figure {
public:
	virtual double perimeter() const = 0;
	virtual double area() const = 0;
};

#endif