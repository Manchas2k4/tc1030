#include <iostream>

void swap(int *a, int *b) {
	int aux;

	aux = (*a);
	(*a) = (*b);
	(*b) = aux;
}

int main(int argc, char* argv[]) {
	int x = 10;
	int y = 20;

	std::cout << "x = " << x << " y = " << y << "\n";

	swap(&x, &y);

	std::cout << "x = " << x << " y = " << y << "\n";

	return 0;
}
