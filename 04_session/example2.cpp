#include <iostream>
#include <cstdlib>
#include <ctime>

const int SIZE = 1000000000; //1e9

int main(int argc, char* argv[]) {
	int data[SIZE];

	srand(time(0));
	for (int i = 0; i < SIZE; i++) {
		data[i] = (rand() % 100) + 1;
	}

	for (int i = 0; i < 100; i++) {
		std::cout << data[i] << " ";
	}
	std::cout << "\n";
	return 0;
}
