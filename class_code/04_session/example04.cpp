#include <iostream>
#include <cstdlib>
#include <ctime>

const int SIZE = 1000000000;

int main(int argc, char* argv[]) {
	int *data;

	data = new int[SIZE];

	std::cout << "Initializing the data...\n";
	srand(time(0));
	for (int i = 0; i < SIZE; i++) {
		data[i] = (rand() % 100) + 1;
	}
	
	std::cout << "Displaying the data...\n";
	for (int i = 0; i < 100; i++) {
		std::cout << data[i] << " ";
	}
	std::cout << "\n";

	delete [] data;

	return 0;
}