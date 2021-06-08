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
#include "exception.h"

int readInputBetween(int low, int high) {
	int num;

	std::cin >> num;
	if (num < low || num > high) {
		throw RangeError();
	}
	return num;
}

int main() {
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int x;
	bool salida;

	salida = false;
	while(!salida) {
		try {
			x = readInputBetween(1, 4);
			salida = true;
		} catch (Exception e) {
			std::cout << "The number must be between 1 and 4\n";
			/* x = 1;
			   break; */
		}
	}
	std::cout << "num = " << x << "\n";
	return 0;
}