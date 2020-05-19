#include <iostream>
#include "figure.h"
#include "rectangle.h"
#include "square.h"

using namespace std;

int main(int argc, char* argv[]) {
	Figure a;
	Rectangle b(10, 20);
	Square c(50);

	cout << "A type = " << a.getType() << " perimeter = " << a.getPerimeter() << " area = " << a.getArea() << "\n";
	cout << "B type = " << b.getType() << " perimeter = " << b.getPerimeter() << " area = " << b.getArea() << "\n";
	cout << "C type = " << c.getType() << " perimeter = " << c.getPerimeter() << " area = " << c.getArea() << "\n";
}