#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	int arr[] = {96, 17, 59, 96, 70, 43, 43, 60, 80, 65};

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";

	int *p = &arr[0]; //int *p = arr;
	bool finished = false;
	while(p <= &arr[9] && !finished) {
		cout << "dir =" << p << ":" << (*p) << "\n";
		if (*p == 100) {
			finished = true;
		}
		p++;
	}
	cout << "\n";

	return 0;
}
