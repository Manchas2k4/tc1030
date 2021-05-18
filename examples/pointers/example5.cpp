#include <iostream>

using namespace std;

void swap(int* a, int* b) {
	int aux;

	aux = (*a);
	(*a) = (*b);
	(*b) = aux;
}

void selectionSort(int* arr, int size) {
	int pos;

	for (int i = size - 1; i > 0; i--) {
		pos = 0;
		for (int j = 1; j <= i; j++) {
			if (arr[pos] < arr[j]) {
				pos = j;
			}
		}

		if (pos != i) {
			swap(&arr[pos], &arr[i]);
		}
	}
}

int main(int argc, char* argv[]) {
	int arr[] = {96, 17, 59, 96, 70, 43, 43, 60, 80, 65};

	selectionSort(arr, 10);
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
	return 0;
}