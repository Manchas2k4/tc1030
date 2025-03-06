#include <iostream>
#include <iomanip>
#include "rational.h"

using namespace std;

int main(int argc, char* argv[]) {
	Rational a;
	Rational b(4);
	Rational c(-1, 2);
	Rational d(2, -4);
	Rational e(-1, -3);
	Rational f(c);
	
	cout << "a: " << a << "\n";
	cout << "b: " << b << "\n";
	cout << "c: " << c << "\n";
	cout << "d: " << d << "\n";
	cout << "e: " << e << "\n";
	cout << "f: " << f << "\n";
	
	Rational z;
	z = c + e;
	cout << "z: " << z << "\n";
	z = c - e;
	cout << "z: " << z << "\n";
	
	cout << "equal? " << (c == e) << "\n";
	cout << "equal? " << (c == d) << "\n";
	
	return 0;
}
