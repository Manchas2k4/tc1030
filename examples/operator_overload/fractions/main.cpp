#include <iostream>
#include "fraction.h"

int main(int argc, char* argv[]) {
	Fraction a(1,3);
	Fraction b(8,9);
	Fraction c, d, e;

	c = (a + b);
	if (a > b) {
		std::cout << "a es mayor que b\n";
	} else {
		std::cout << "a NO es mayor que b\n";
	}
	d = a + 7;
	e = 10 + b;
	std::cout << "a = " << a << "\n" << "b = " << b << "\n"  
						<< "c = " << c << "\n" << "d = " << d << "\n"
						<< "e = " << e << "\n";

}