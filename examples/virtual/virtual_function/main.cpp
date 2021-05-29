#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "character.h"
#include "hero.h"
#include "enemy.h"

int main(int argc, char* argv[]) {
	Enemy *enemy;
	Hero h("The Migthy Akator", 3, 3, 2, 6);
	std::string name = "Enemy Lvl. ";
	int level, count;

	srand(time(0));

	level = 1;
	count = 0;
	enemy = new Enemy(name + std::to_string(level), level, level,
										level * 10);
	while(h.isAlive()) {
		while (h.isAlive() && enemy->isAlive()) {
			if (enemy->attack() > h.defense()) {
				std::cout << enemy->getDescription() << " has attacked\n";
				h.takeDamage();
			} else {
				std::cout << enemy->getDescription() << " has failed\n";
			}

			if (h.attack() > enemy->defense()) {
				std::cout << h.getDescription() << " has attacked\n";
				enemy->takeDamage();
			} else {
				std::cout << h.getDescription() << " has failed\n";
			}

			std::cout << "Hero health = " << h.getHealth()
								<< "\tEnemy health = " << enemy->getHealth()
								<< ".\n";
		}

		if (!enemy->isAlive()) {
			h.addTreasure(enemy->getReward());
			std::cout << "\n" << h.getDescription() << " wins\n";
			std::cout << "Treasure = " << h.getTreasure() << "\n\n";

			delete enemy;

			count++;
			if (count == 3) {
				level++;
				count = 0;
			}

			enemy = new Enemy(name + std::to_string(level), level, level,
												level * 10);
		} else {
			std::cout << "\n" << enemy->getDescription() << " wins\n\n";
		}
	}

	std::cout << "OMG! The final treasure of " << h.getDescription()
						<< " is " << h.getTreasure()<< ".\n";

	return 0;
}
