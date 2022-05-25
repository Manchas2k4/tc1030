#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

const int PI = 3.14159265;
const int RECTS = 100000000; //1e9

double linear(double x) {
	return x;
}

double square(double x) {
	return x * x;
}

double cube(double x) {
	return x * x * x;
}

double integration(double inf, double sup, double (*fn) (double)) {
	double high, dx, acum, x;
	int i;

	if (sup < inf) {
		swap(inf, sup);
	}

	x = inf;
	dx = (sup - inf) / RECTS;
	acum = 0;
	for (i = 0; i < RECTS; i++) {
		acum += fn(x + (i * dx));
	}
	acum = acum * dx;
	return acum;
}

int main(int argc, char* argv[]) {
	int i;
	double result;

	cout << "Starting...\n";

	result = integration(0, PI, sin);
	cout << "Result = " << result << "\n";

	result = integration(0, 100, linear);
	cout << "Result = " << result << "\n";

	result = integration(0, 100, square);
	cout << "Result = " << result << "\n";

	result = integration(0, 100, cube);
	cout << "Result = " << result << "\n";

	return 0;
}
