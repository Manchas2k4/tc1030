/*************************************************************
* File: scroll.h
* Author: Pedro Perez
* Description: This file contains the definition of Scroll
*							 class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#ifndef SCROLL_H
#define SCROLL_H

#include "item.h"

class Scroll : public Item {
private:
	uchar month;

public:
	Scroll();
	Scroll(uint, std::string, uchar, int, bool);
	Scroll(std::string);
	Scroll(const Scroll&);

	uchar getMonth() const;

	void setMonth(uchar);

	std::string toString() const;
};

#endif
