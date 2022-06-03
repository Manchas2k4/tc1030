#include <iostream>
#include "figure.h"
#include "circle.h"
#include "rectangle.h"
#include "square.h"

using namespace std;

int main(int argc, char* argv[]) {
	Figure a;
	Circle b(10);
	Rectangle c(10, 20);
	Square d(50);

	cout << "A " << a.toString() << "\n";
	cout << "B " << b.toString() << "\n";
	cout << "C " << c.toString() << "\n";
	cout << "D " << d.toString() << "\n";
}
