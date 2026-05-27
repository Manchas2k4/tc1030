#include <iostream>
#include <iomanip>
#include "vector.h"

using namespace std;

int main(int argc, char* argv[]) {
	Vector a;
	Vector b(10);
	Vector c(5, -1);
	
	cout << "A: "; a.display();
	cout << "B: "; b.display();
	cout << "C: "; c.display();
	
	cout << "B[3]: " << b.at(3) << "\n";
	
	b.set(3, 400);
	cout << "B: "; b.display();
	
	c.resize(10, 1);
	cout << "C: "; c.display();
	return 0;
}
