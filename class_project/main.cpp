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
#include <vector>
#include "utils.h"
#include "user.h"
//#include "date.h"

int main() {
	std::string input;
	User a;

	getline(std::cin, input);
	a = User(input);
	std::cout << a.toString();
	return 0;
}
