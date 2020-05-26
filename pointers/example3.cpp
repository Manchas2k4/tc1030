#include <iostream>

using namespace std;

const int SIZE = 40000000;

int main(int argc, char* argv[]) {
	//int arreglo[SIZE];

	int *arreglo = new int[SIZE];

	for (int i = 0; i < SIZE; i++) {
		arreglo[i] = i;
	}

	for (int i = 0; i < 20; i++) {
		cout << arreglo[i] << " ";
	}
	cout << "\n";

	delete [] arreglo;

	return 0;
}
	