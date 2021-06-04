/*************************************************************
* File: enemy.cpp
* Author: Pedro Perez
* Description: This file contains the implementation of
*              Enemy class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#include "enemy.h"

Enemy::Enemy()
  : Character("A simple enemy") {
  reward = rand() & 5 + 6;
}

Enemy::Enemy(std::string d, int da, int sh, int re)
  : Character(d, da, sh), reward(re) {
}

Enemy::Enemy(const Enemy &e)
  : Character(e.description, e.damageDice, e.shieldDice),
    reward(e.reward) {
}

int Enemy::getReward() const {
  return reward;
}

void Enemy::setReward(int r) {
  reward = r;
}
