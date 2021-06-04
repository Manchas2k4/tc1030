/*************************************************************
* File: character.cpp
* Author: Pedro Perez
* Description: This file contains the implementation of
*              Character class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#include "character.h"

Character::Character()
	: description("Just a simple character"), health(3),
		damageDice(1), shieldDice(1) {
}

Character::Character(std::string d)
	: description(d), health(3), damageDice(1), shieldDice(1) {
}

Character::Character(std::string d, int da, int sh)
	:description(d), health(3), damageDice(da), shieldDice(sh) {
}

Character::Character(const Character &c)
	:description(c.description), health(c.health),
	 damageDice(c.damageDice), shieldDice(c.shieldDice) {
}

std::string Character::getDescription() const {
	return description;
}

int Character::getHealth() const {
	return health;
}

int Character::getDamageDice() const {
	return damageDice;
}

int Character::getShieldDice() const {
	return shieldDice;
}

void Character::setDescription(std::string d) {
	description = d;
}

void Character::setHealth(int h) {
	health = h;
}

void Character::setDamageDice(int d) {
	damageDice = d;
}

void Character::setShieldDice(int d) {
	shieldDice = d;
}

void Character::takeDamage() {
	if (health > 0) {
		health--;
	}
}

bool Character::isAlive() const {
	return (health != 0);
}

int Character::getMaximum(int limit) const {
	int aux, result = 0;

	for (int i = 0; i < limit; i++) {
		aux = (rand() % 6) + 1;
		if (result < aux) {
			result = aux;
		}
	}

	return result;
}

int Character::attack() const {
	return getMaximum(damageDice);
}

int Character::defense() const {
	return getMaximum(shieldDice);
}

std::ostream& operator<< (std::ostream& out, const Character &character) {
	out << character.getDescription() << " Health = " 
			<< character.getHealth();
	return out;
}