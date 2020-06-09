#include <iostream>
#include "set.h"

using namespace std;

int main(int argc, char* argv[]) {
	Set a(10), b(10), c(20);

	a.add(1); a.add(3); a.add(5);
	cout << "A = " << a.toString() << "\n";
	b.add(3); b.add(7); b.add(1); b.add(9);
	cout << "B = " << b.toString() << "\n";
	c.add(2); c.add(3); c.add(5); c.add(6); c.add(12); c.add(15); c.add(19);
	cout << "C = " << c.toString() << "\n";

	Set *result;
	result = a.intersection(b);
	if (result != NULL) {
		cout << "A inter B = " << result->toString() << "\n";
	} else {
		cout << "Null pointer\n";
	}

	delete result;
	result = a.intersection(c);
	if (result != NULL) {
		cout << "A inter C = " << result->toString() << "\n";
	} else {
		cout << "Null pointer\n";
	}

	delete result;
	result = a.join(c);
	if (result != NULL) {
		cout << "A union C = " << result->toString() << "\n";
	} else {
		cout << "Null pointer\n";
	}

	delete result;
	result = c.diference(a);
	if (result != NULL) {
		cout << "C - A = " << result->toString() << "\n";
	} else {
		cout << "Null pointer\n";
	}

	delete result;

	return 0;
}