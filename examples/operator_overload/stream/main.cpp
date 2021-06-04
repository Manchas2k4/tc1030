#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "hero.h"
#include "room.h"

int main(int argc, char* argv[]) {
	Hero h("The Migthy Akator", 3, 3, 2, 6);
	Room *room;
	int level = 1;
	char option;
	bool cont;

	srand(time(0));
	cont = true;
	do {
		room = new Room(level);
		if (room->passEncounter(&h) == true) {
			level = level + 1;
			delete room;
		} else {
			level = 1;
		}

		if (h.isAlive()) {
			std::cout << "What do you want to do?" << "\n"
						<< "c)Continue" << "\n" << "e)Exit" << "\n";
			std::cin >> option;
			if (option == 'e') {
				cont = false;
			}
		} else {
			cont = false;
		}
	} while (cont == true);
	return 0;
}
