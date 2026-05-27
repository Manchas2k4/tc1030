#include <iostream>
#include <cstdlib>
#include <vector>
#include "figure.h"
#include "circle.h"
#include "rectangle.h"
#include "square.h"

using namespace std;

int main(int argc, char* argv[]) {
	vector<Figure*> v(20);
	int val;
	double average;

	srand(1234);
	for (int i = 0; i < v.size(); i++) {
		val = rand() % 3;
		switch(val) {
			case 0 : v[i] = new Circle((rand() % 100) + 1); cout << "Adding a circle\n"; break;
			case 1 : v[i] = new Rectangle((rand() % 100) + 1, (rand() % 100) + 1); cout << "Adding a rectangle\n"; break;
			case 2 : v[i] = new Square((rand() % 100) + 1); cout << "Adding a square\n"; break;
		}
	}

	for (Figure* fig : v) {
		cout << fig->toString() << "\n";
	}

	average = 0;
	for (Figure* fig : v) {
		average += fig->getPerimeter();
	}
	cout << "Average of the perimeters = " << (average / v.size()) << "\n";

	average = 0;
	for (Figure* fig : v) {
		average += fig->getArea();
	}
	cout << "Average of the perimeters = " << (average / v.size()) << "\n";
}
