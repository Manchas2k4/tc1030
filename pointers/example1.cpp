#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	int x = 100;
	int *p = &x;

	cout << "x = " << x << "\n";
	cout << "valor al que hace referencia p = " << *p << "\n";

	cout << "localidad de x: " << (&x) << "\n";
	cout << "valor de p: " << p << "\n";

	*p = 15;

	cout << "x = " << x << "\n";
	cout << "valor al que hace referencia p = " << *p << "\n";

	p = p + 1;
	cout << "localidad de x: " << (&x) << "\n";
	cout << "valor de p: " << p << "\n";

	*p = 10;
	cout << "valor de p: " << p << "\n";
	cout << "valor al que hace referencia p = " << *p << "\n";
	
	return 0;
}