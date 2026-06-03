#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class Enemy : public Character {
public:
    Enemy() 
    : Character()
    {}

    Enemy(const Enemy &e)
    : Character(e)
    {}
    
    Enemy(std::string n, int mh, int s, int a, double cc, double cm, double mc, int scd1, int scd2)
    : Character(n, mh, s, a, cc, cm, mc, scd1, scd2)
    {}
};

#endif