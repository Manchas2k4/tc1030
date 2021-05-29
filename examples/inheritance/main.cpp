#include <iostream>
#include "package.h"
#include "twoday.h"
#include "overnight.h"

int main(int argc, char* argv[]) {
	Package a("uno", "dos", 2.0, 15.0);
	Package d("tres", "cuatro", 3, 40.0);
	TwoDayPackage b("uno", "dos", 2.0, 15.0, 40);
	OvernightPackage c("uno", "dos", 2.0, 15.0, 5.0);

	std::cout << "Package = " << a.calculateCost() << "\n";
	std::cout << "Package = " << d.calculateCost() << "\n";
	std::cout << "TwoDayPackage = " << b.calculateCost() << "\n";
	std::cout << "OvernightPackage = " << c.calculateCost() << "\n";
	return 0;
}