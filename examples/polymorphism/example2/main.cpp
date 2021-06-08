#include <iostream>
#include <cstdlib>
#include <ctime>
#include "currency.h"

#define SIZE 10

int main(int argc, char* argv[]) {
	Currency* arr[SIZE];
	double val;

	srand(time(0));
	for (int i = 0; i < SIZE; i++) {
		val = (rand() % 10000) + 1.0;
		if (rand() % 2 == 0) {
			arr[i] = new Peso(val);
		} else {
			arr[i] = new Dollar(val);
		}
	}

	for (int i = 0; i < SIZE; i++) {
		std::cout << "type = " << arr[i]->getType() << " val = " 
							<< arr[i]->getUSD() << " dolares\n";
	}
	std::cout << "\n";
	for (int i = 0; i < SIZE; i++) {
		std::cout << "type = " << arr[i]->getType() << " val = " 
							<< arr[i]->getMXN() << " pesos\n";
	}

	int acum = 0;
	int total = 0;
	for (int i = 0; i < SIZE; i++) {
		if (arr[i]->getType() == PESOS) {
			acum++;
			total += arr[i]->getMXN(); 
		}
	}
	std::cout << "Hay " << acum << " monedas de pesos.\n";
	std::cout << "En total, hay " << total << " pesos.\n";
	return 0;
}