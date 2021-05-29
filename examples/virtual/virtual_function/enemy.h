/*************************************************************
* File: enemy.h
* Author: Pedro Perez
* Description: This file contains the definition of
*              Enemy class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/

#include <iostream>
#include "character.h"

class Enemy : public Character {
private:
  int reward;

public:
    Enemy();
    Enemy(std::string, int, int, int);
    Enemy(const Enemy&);

    int getReward() const;

    void setReward(int);
};
