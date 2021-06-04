/*************************************************************
* File: room.cpp
* Author: Pedro Perez
* Description: This file contains the implementation of
*              Room class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#include "room.h"

Room::Room() {
	enemy = new Enemy("This a simple guy", 1, 1, 1);
}

Room::Room(int level) {
	enemy = new Enemy("A Mighty Warrior Level " + level, level, 
										level, level * 100);
}

Room::Room(const Room &r) {
	//enemy = new Enemy(r.enemy);
}

bool Room::passEncounter(Hero *hero)  {
	char option;
	bool cont;

	std::cout << "As soon you enter the room, you see " 
						<< enemy->getDescription() << "\n"; 

	cont = true;
	do {
		std::cout << "What do you want to do?" << "\n"
							<< "r)Run" << "\n" << "f)fight" << "\n";
		std::cin >> option;
		if (option == 'r') {
			cont = false;
			continue;
		}
	
		if (enemy->attack() > hero->defense()) {
			std::cout << enemy->getDescription() << " has attacked\n";
			hero->takeDamage();
		} else {
			std::cout << enemy->getDescription() << " has failed\n";
		}

		if (hero->attack() > enemy->defense()) {
			std::cout << hero->getDescription() << " has attacked\n";
			enemy->takeDamage();
		} else {
			std::cout << hero->getDescription() << " has failed\n";
		}

		std::cout << (*hero) << "\n" << (*enemy) << "\n";
	} while (cont == true && hero->isAlive() && enemy->isAlive());

	if (cont == false) {
		return false;
	}

	if (!hero->isAlive()) {
		std::cout << "\n" << enemy->getDescription() << " wins\n\n";
		return false;
	}

	if (!enemy->isAlive()) {
		hero->addTreasure(enemy->getReward());
		std::cout << "\n" << hero->getDescription() << " wins\n";
		std::cout << "Treasure = " << hero->getTreasure() << "\n\n";
		return true;
	} 

	return true;	
}