#include <iostream>
#include <cstdlib>
#include <ctime>
#include "circle.h"
#include "rectangle.h"

int main(int argc, char* argv[]) {
	Figure* fig[10];
	int type;

	srand(time(0));
	for (int i = 0; i < 10; i++) {
		type = rand() % 2;
		switch(type) {
			case 0 : std::cout << "Rectangle\n"; fig[i] = new Rectangle(10, 20); break;
			case 1 : std::cout << "Circle\n"; fig[i] = new Circle(10); break;
		}
	}

	for (int i = 0; i < 10; i++) {
		std::cout << "Figure " << (i + 1) << "\n";
		std::cout << "Area = " << fig[i]->area() << "\n";
		std::cout << "Perimeter = " << fig[i]->perimeter() << "\n";
	}

	for (int i = 0; i < 10; i++) {
		delete fig[i];
	}
	return 0;
}