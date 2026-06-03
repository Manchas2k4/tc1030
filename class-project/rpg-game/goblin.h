#ifndef GOBLIN_H
#define GOBLIN_H

#include "enemy.h"
#include "console.h"
#include "warrior.h"
#include "archer.h"
#include "wizard.h"

class Goblin : public Enemy {
public:
    Goblin() 
    : Enemy()
    {}

    Goblin(const Goblin &g)
    : Enemy(g)
    {}
    
    Goblin(std::string n)
    : Enemy(n, 50, 12, 3, 0.15, 1.5, 0.05, 3, 5)
    {}

    void attack(std::vector<Character*> v) {
        int enemy = -1;
        int minimum = 10;
        int value = -1;
        for (int i = 0; i < v.size(); i++) {
            if (dynamic_cast<Wizard*>(v[i])) {
                value = 0;
            } else if (dynamic_cast<Archer*>(v[i])) {
                value = 1;
            } else if (dynamic_cast<Warrior*>(v[i])) {
                value = 2;
            }

            if (minimum > value) {
                minimum = value;
                enemy = i;
            }
        }

        if (enemy == - 1) {
            std::cout << "There are no valid targets to attack.\n";
            return;
        }

        std::cout << name << " is going to attack " << v[enemy]->getName() << ".\n";
        if (!v[enemy]->isAlive()) {
            std::cout << name << "is so stupid that he attacks a dead hero.\n";
            return;
        }

        int attack = 1;
        if (minimum == 0 || minimum == 1) {
            if (canUseSkill2()) {
                attack = 3;
            }
        } else if (minimum == 3) {
            if (canUseSkill1()) {
                attack = 2;
            }
        }

        int damage = 0;
        switch(attack) {
            case 1 : 
                damage = basicAttack();
                std::cout << name << " used Basic Attack!\n";
                break;
            case 2 : 
                damage = skillAttack1();
                break;
            case 3 : 
                damage = skillAttack2();
                break;
        }

        if (damage > 0) {
            v[enemy]->receiveDamage(damage);
        }

        if (attack == 3) {
            v[enemy]->applyPoison(3);
        }
    }
    
    int skillAttack1() override {
        if (!canUseSkill1()) {
            std::cout << "Skill unavailable!\n";
            return 0;
        }

        int damage = 16;
        currentCooldown1 = skillCooldown1;
        std::cout << name << " used Quick Strike!\n";

        return damage;
    }

    int skillAttack2() override {
        if (!canUseSkill2()) {
            std::cout << "Skill unavailable!\n";
            return 0;
        }

        int damage = 6;
        currentCooldown2 = skillCooldown2;
        std::cout << name << " used Dirty Stab!\n";
        
        return damage;
    }

};

#endif