#include <iostream>
#include <cstdlib>
#include <ctime>
#include "character.h"
#include "hero.h"

int main(int argc, char* argv[]) {
	Character x("A simple guy", 2, 2);
	Hero h;
	int result;

	srand(time(0));

	while(h.getHealth() != 0 && x.getHealth() != 0) {
		if (x.attack() > h.defense()) {
			std::cout << "Simple guy has attacked\n";
			h.setHealth(h.getHealth() - 1);
		} else {
			std::cout << "Simple guy has failed\n";
		}

		if (h.attack() > x.defense()) {
			std::cout << "Hero has attacked\n";
			x.setHealth(x.getHealth() - 1);
		} else {
			std::cout << "Hero has failed\n";
		}
	}

	if (h.getHealth() != 0) {
		std::cout << "The hero wins\n";
	} else {
		std::cout << "The simple guy wins\n";
	}
	return 0;
}