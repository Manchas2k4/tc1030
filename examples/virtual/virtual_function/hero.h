/*************************************************************
* File: hero.h
* Author: Pedro Perez
* Description: This file contains the definition of
*              Hero class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#ifndef HERO_H
#define HERO_H

#include "character.h"

class Hero : public Character {
private:
	int bonusShield, used;
	int treasure;

public:
	Hero();
	Hero(std::string, int, int, int, int);
	Hero(const Hero&);

	int getTreasure() const;

	void setTreasure(int);

	void addTreasure(unsigned int);

	int defense();
};

#endif
