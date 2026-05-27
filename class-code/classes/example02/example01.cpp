#include <iostream>
#include <iomanip>
#include "vector.h"

using namespace std;

int main(int argc, char* argv[]) {
	Vector a;
	Vector b(10);
	Vector c(5, -1);
	
	cout << "A: " << a << "\n";
	cout << "B: " << b << "\n";
	cout << "C: " << c << "\n";
	
	cout << "B[3]: " << b[3] << "\n";
	
	b[3] = 400;
	cout << "B: " << b << "\n";
	
	c.resize(10, 1);
	cout << "C: " << c << "\n";
	return 0;
}
