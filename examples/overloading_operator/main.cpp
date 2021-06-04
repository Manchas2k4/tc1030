#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "cell.h"
#include "animal.h"

#define SIZE 			20
#define PCTSHARKS	0.05
#define PCTFISHES	0.20

typedef unsigned int uint;

std::vector<uint> randomSet(uint n) {
	std::vector<uint> result;
	int count, pos1, pos2, aux;

	for (uint i = 0; i < n; i++) {
		result.push_back(i);
	}

	count = n / 2;
	while (count > 0) {
		pos1 = rand() % n;
		pos2 = rand() % n;

		aux = result[pos1];
		result[pos1] = result[pos2];
		result[pos2] = aux;

		count--;
	}

	return result;
}

int dec(int pos) {
	return ((pos - 1) < 0)? SIZE - 1 : (pos - 1);
}

int inc(int pos) {
	return ((pos + 1) >= SIZE)? 0 : (pos + 1);
}

class Simulation {
private:
	Cell cells[SIZE][SIZE];
	uint current, limit;

public:
	Simulation(uint s);
	void oneStep();
	void display() const;
	void run();
};

Simulation::Simulation(uint lim) {
	Animal *aux;
	int row, col, j;
	int fishes = (int) (SIZE * SIZE * PCTFISHES);
	int sharks = (int) (SIZE * SIZE * PCTSHARKS);
	std::vector<uint> cellPos = randomSet(SIZE * SIZE);

	current = 0;
	limit = lim;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cells[i][j] = Cell(&cells[dec(i)][j],
												 &cells[i][inc(j)],
												 &cells[inc(i)][j],
												 &cells[i][dec(j)]);
		}
	}

	j = 0;
	for (int i = 0; i < fishes; i++) {
		row = cellPos[j] / SIZE;
		col = cellPos[j] % SIZE;
		aux = new Fish(&cells[row][col]);
		cells[row][col].setContent(aux);
		Animal::animals.push_back(aux);
		j++;
	}
	for (int i = 0; i < sharks; i++) {
		row = cellPos[j] / SIZE;
		col = cellPos[j] % SIZE;
		aux = new Shark(&cells[row][col]);
		cells[row][col].setContent(aux);
		Animal::animals.push_back(aux);
		j++;
	}
}

void Simulation::oneStep() {
	for (int i = 0; i < Animal::animals.size(); i++) {
		if (Animal::animals[i]->isAlive()) {
			Animal::animals[i]->move();
		}
	}
}

void Simulation::display() const {
	std::cout << "STEP " << current << "\n";
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (cells[i][j].getContent() == NULL ||
					!cells[i][j].getContent()->isAlive()) {
				std::cout << "~";
			} else {
				if (cells[i][j].getContent()->getAnimalType() == SHARK) {
					std::cout << "S";
				} else {
					std::cout << "F";
				}
			}
			std::cout << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n\n";
}

void Simulation::run() {
	while (current < limit) {
		display();
		oneStep();
		current++;
		sleep(1);
	}
}

int main(int argc, char* argv[]) {
	Simulation sim(50);

	//srand(time(0));
	srand(123);
	sim.run();
	return 0;
}
