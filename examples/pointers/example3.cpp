#include <iostream>

int main(int argc, char* argv[]) {
	int var = 10;
	int *p = &var;

	std::cout << "var = " << var << "\n";
	std::cout << "var address = " << &var << "\n";
	std::cout << "p = " << p << "\n";

	var = var + 10;

	std::cout << "var = " << var << "\n";

	(*p) = (*p) + 10;

	std::cout << "var = " << var << "\n";

	return 0;
}