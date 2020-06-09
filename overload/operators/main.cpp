/**
    File: using_rational.cpp
    Purpose: This file uses the rational class in different operations.

    @author Pedro Perez
    @version 2.0 06/01/2020
*/
#include <iostream>
#include "rational.h"

using namespace std;

int main(int argc, char* argv[]) {
	Rational a, b(5), c(18, 24);

	cout << "a = " << a.toString() << " b = " << b.toString() << " c = " << c.toString() << "\n";
	a = b;
	cout << "a = " << a.toString() << " b = " << b.toString() << " c = " << c.toString() << "\n";
	a += c;
	cout << "a = " << a.toString() << " b = " << b.toString() << " c = " << c.toString() << "\n";

	Rational d;
	d = a + c;
	cout << "d = " << d.toString() << "\n";

	if (a < b) {
		cout << "a is less than b";
	} else {
		cout << "a is not less than b";
	}
	cout << "\n";

	return 0;
}
