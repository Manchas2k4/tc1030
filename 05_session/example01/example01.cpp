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
	
	cout << "a: "; a.display(); cout << "\n";
	cout << "b: "; b.display(); cout << "\n";
	cout << "c: "; c.display(); cout << "\n";
	cout << "d: "; d.display(); cout << "\n";
	cout << "e: "; e.display(); cout << "\n";
	cout << "f: "; f.display(); cout << "\n";
	
	Rational z;
	z = c.add(e);
	cout << "z: "; z.display(); cout << "\n";
	z = c.sub(e);
	cout << "z: "; z.display(); cout << "\n";
	
	cout << "equal? " << c.equals(e) << "\n";
	cout << "equal? " << c.equals(d) << "\n";
	
	return 0;
}
