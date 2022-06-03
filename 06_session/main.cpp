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

	cout << "A type = " << a.getType() << " perimeter = " << a.getPerimeter() << " area = " << a.getArea() << "\n";
	cout << "B type = " << b.getType() << " perimeter = " << b.getPerimeter() << " area = " << b.getArea() << "\n";
	cout << "C type = " << c.getType() << " perimeter = " << c.getPerimeter() << " area = " << c.getArea() << "\n";
	cout << "D type = " << d.getType() << " perimeter = " << d.getPerimeter() << " area = " << d.getArea() << "\n";
}
