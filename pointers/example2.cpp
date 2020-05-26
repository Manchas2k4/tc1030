#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	int *p = new int;

	*p = 42;
	if ( (*p) % 2  == 0 ) {
		cout << "PAR\n";
	} else {
		cout << "IMPAR\n";
	}

	cout << "valor de p: " << p << "\n";
	cout << "valor al que hace referencia p = " << *p << "\n";

	delete p;

	return 0;
}
