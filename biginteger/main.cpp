#include <iostream>
#include "biginteger.h"

using namespace std;

int main(int argc, char* argv[]) {
	BigInteger a(string("1999"));
	BigInteger b(string("1"));

	cout << "A = " << a.toString() << "\n";
	cout << "B = " << b.toString() << "\n";
	a.add(b);
	cout << "A = " << a.toString() << "\n";

	BigInteger c;
	c.add(a, b);
	cout << "C = " << c.toString() << "\n";
	
	return 0;
}