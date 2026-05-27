#include <iostream>
#include <iomanip>

using namespace std;

void swap(int &a, int &b) {
	int aux;
	
	aux = a;
	a = b;
	b = aux;
	cout << "a = " << a << " b = " << b << "\n";
}

void swap(float &a, float &b) {
	float aux;
	
	aux = a;
	a = b;
	b = aux;
	cout << "a = " << a << " b = " << b << "\n";
}

int main(int argc, char* argv[]) {
	int x = 10;
	int y = 5;
	
	cout << "x = " << x << " y = " << y << "\n";
	
	swap(x, y);
	
	cout << "x = " << x << " y = " << y << "\n";
	
	return 0;
}
