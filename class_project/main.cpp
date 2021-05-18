/*************************************************************
* File: main.cpp
* Author: Pedro Perez
* Description: 
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#include <iostream>
#include "item.h"
#include "date.h"

int main() {
	Item a;
  Item b(BOOK, 1, "El Ingenioso hidalgo Don Quixote de la Manchas", 2020, false);
	Item c(b);

	std::cout << "item = " << a.toString() << "\n";
	std::cout << "item = " << b.toString() << "\n";
	std::cout << "item = " << c.toString() << "\n";

	Date x;
	Date y(32, 2, 1900);
	Date z(y);

	std::cout << "date = " << x.toString() << "\n";
	std::cout << "date = " << y.toString() << "\n";
	std::cout << "date = " << z.toString() << "\n";

	return 0;
}