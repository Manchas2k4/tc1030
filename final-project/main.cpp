#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "character.h"
#include "level.h"

using namespace std;

vector<Level*> levels(3);
Character *hero;

void createHero() {
	string name;
	int option;

	cout << "What is your hero's name? ";
	cin >> name;
	cin.ignore();

	cout << "0. Warrior\n";
	cout << "1. Archer\n";
	cout << "2. Mage\n";
	cout << "What kind of hero do you want to be? ";
	cin >> option;

	option %= 3;

	switch(option) {
		case 0 : hero = new Warrior(name); break;
		case 1 : hero = new Archer(name); break;
		case 2 : hero = new Mage(name); break;
	}
}

void createLevels() {
	levels[0] = new Level("The Duel in the Goblin's Lair");
	levels[0]->addPrologue("The hero entered a foggy forest. Twisted trees whispered secrets. In a moonlit clearing, a mighty goblin appeared, ready to battle.");
	levels[0]->addEpilogue("The hero bravely defeated the goblin. Exhausted but victorious, he looked at the sunrise, ready for future challenges.");
	levels[0]->addEnemy(new Enemy("Goblin", 25, 15, 5));
	levels[0]->addHero(hero);

	levels[1] = new Level("The Battle of the Shadow Cave");
	levels[1]->addPrologue("The cave was dark and damp, with stalactites, bats, and an oppressive atmosphere. An orc awaited the hero by a fire.");
	levels[1]->addEpilogue("The hero, bleeding but victorious, defeated the orc. Exhausted, he picked up his sword and set out for new adventures.");
	levels[1]->addEnemy(new Enemy("Orc", 75, 45, 15));
	levels[1]->addHero(hero);

	levels[2] = new Level("The Confrontation at the Frosty Peak");
	levels[2]->addPrologue("On the snowy mountaintop, the hero faced the red dragon. Icy wind whipped as the dragon roared, its scales glistening. Battle imminent.");
	levels[2]->addEpilogue("The hero stood over the fallen dragon. Wind scattered ashes. Sword smoking, he looked out over the snowy landscape, triumphant.");
	levels[2]->addEnemy(new Enemy("Dragon", 100, 60, 30));
	levels[2]->addHero(hero);
}

void deleteAll() {
	for (Level *lvl : levels) {
		delete lvl;
	}
}

int main(int argc, char* argv[]) {
	int option, i = 0; 
	bool finished = false;

	createHero();

	createLevels();

	cout << "\nIn the Kingdom of Eldoria, peace is shattered when the "
		 << "necromancer Sarvok seeks the Stone of Eternity to gain "
		 << "unlimited power. Guided by a prophecy, three heroes—a "
		 << "Warrior, an Archer, and a Mage—set out on a journey to stop "
		 << "Sarvok from achieving his goal, facing many dangers along the way.\n";
		 cout << "----------------------------------------------------\n\n";

	while (!finished && i < levels.size()) {
		levels[i]->execute();
		if (!levels[i]->hasWon()) {
			finished = true;
		} else {
			cout << hero->toString() << "\n";
			cout << "Do you want to rest? ";
			cin >> option;
	
			if (option != 0) {
				hero->recover();
			}
		}
		i++;
	}

	if (i >= levels.size() && levels[i-1]->hasWon()) {
		cout << "After arduous battles, the heroes reached the Dark Fortress "
			 << "and defeated Sarvok, sealing the Eternity Stone. Eldoria flourished "
			 << "and the heroes were celebrated. Their legacy continues to inspire, "
			 << "maintaining peace and justice in the realm.\n";
	}

	deleteAll();

	return 0;
}