#include <iostream>

using namespace std;

const int SIZE = 20;

int main(int argc, char* argv[]) {
	int arr[SIZE];

	arr[5] = 1;
	cout << "localidad 5 : " << arr[5] << "\n";

	*(arr + 5) = 3;
	cout << "localidad 5 : " << arr[5] << "\n";

	*(5 + arr) = 6;
	cout << "localidad 5 : " << arr[5] << "\n";

	5[arr] = 12;
	cout << "localidad 5 : " << arr[5] << "\n";

	for (int i = 0; i < SIZE; i++) {
		i[arr] = i;
	}

	for (int i = 0; i < SIZE; i++) {
		cout << arr[i] << "\n";
	}
	return 0;
}