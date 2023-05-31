#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	int arr[] = {96, 17, 59, 96, 70, 43, 43, 60, 80, 65};

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
    cout << "\n";

    for (int i = 0; i < 10; i++) {
		cout << *(arr + i) << " ";
	}
	cout << "\n";

    for (int i = 0; i < 10; i++) {
		cout << i[arr] << " ";
	}
	cout << "\n";

     for (int *i = arr; i < &arr[10]; i++) {
		cout << *i << " ";
	}
	cout << "\n";

    return 0;
}