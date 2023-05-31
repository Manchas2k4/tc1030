#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

const int SIZE = 1000000000;

int main(int argc, char* argv[]) {
	int *data;

	data = new int[SIZE];

	std::cout << "Initializing the data...\n";
	memset(data, 0, SIZE * sizeof(int));
	
	std::cout << "Displaying the data...\n";
	for (int i = 0; i < 100; i++) {
		std::cout << data[i] << " ";
	}
	std::cout << "\n";

	delete [] data;

	return 0;
}