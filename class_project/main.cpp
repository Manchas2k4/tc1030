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
#include "ucatalog.h"
//#include "date.h"

int main() {
	UserCatalog uc(1);
	UserCatalog uc2(1);

	uc.addUser(new User(1, "Juan Hernandez"));
	std::cout << uc.toString();

	uc.addUser(new User(2, "Luis Hernandez"));
	std::cout << uc.toString();

	uc.addUser(new User(3, "Otto Kuate"));
	std::cout << uc.toString();

	uc.save("users.txt");

	uc2.load("users.txt");
	std::cout << uc2.toString();
	return 0;
}
