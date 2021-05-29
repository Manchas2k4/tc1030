/*************************************************************
* File: hero.cpp
* Author: Pedro Perez
* Description: This file contains the implementation of
*              Hero class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#include "hero.h"

Hero::Hero()
	: Character("Ragnar, the Brave", 2, 2), bonusShield(0), used(0) {
}

Hero::Hero(std::string d, int da, int sh, int b, int u)
	: Character(d, da, sh), bonusShield(b), used(u) {
}

Hero::Hero(const Hero &h)
	: Character(h.description, h.damageDice, h.shieldDice),
		bonusShield(h.bonusShield), used(h.used) {
}

int Hero::defense() {
	if (used != 0) {
		used--;
		return getMaximum(shieldDice + bonusShield);
	} else {
		return getMaximum(shieldDice);
	}
}
