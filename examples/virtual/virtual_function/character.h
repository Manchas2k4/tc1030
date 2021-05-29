/*************************************************************
* File: character.h
* Author: Pedro Perez
* Description: This file contains the definition of
*              Character class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>

class Character {
protected:
	std::string description;
	int health, damageDice, shieldDice;

	int getMaximum(int) const;

public:
	Character();
	Character(std::string);
	Character(std::string, int, int);
	Character(const Character&);

	std::string getDescription() const;
	int getHealth() const;
	int getDamageDice() const;
	int getShieldDice() const;

	void setDescription(std::string);
	void setHealth(int);
	void setDamageDice(int);
	void setShieldDice(int);

	void takeDamage();
	bool isAlive() const;

	virtual int attack() const;
	virtual int defense() const;
};

#endif
