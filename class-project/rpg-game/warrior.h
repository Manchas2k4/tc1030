#ifndef WARRIOR_H
#define WARRIOR_H

#include "hero.h"

class Warrior : public Hero {
private:
    int passiveDefense;

public:
    Warrior() 
    : Hero(), passiveDefense(2)
    {}

    Warrior(const Warrior &w)
    : Hero(w), passiveDefense(2)
    {}
    
    Warrior(std::string n)
    : Hero(n, 140, 18, 12, 0.10, 1.5, 0.05, 3, 4, 30, 2, 8, 10), passiveDefense(2)
    {}

    void receiveDamage(int damage) override {
        damage -= passiveDefense;
        if (damage < 0) {
            damage = 0;
        }

        Character::receiveDamage(damage);
    }

    int skillAttack1() override {
        if (!canUseSkill1()) {
            std::cout << "Skill unavailable!\n";
            return 0;
        }

        int damage = 10;
        useMana(manaCost1);
        currentCooldown1 = skillCooldown1;
        std::cout << name << " used Shield Bash!\n";

        return damage;
    }

    int skillAttack2() override {
        if (!canUseSkill2()) {
            std::cout << "Skill unavailable!\n";
            return 0;
        }

        int damage = 30;
        useMana(manaCost2);
        currentCooldown2 = skillCooldown2;
        std::cout << name << " used Heavy Slash!\n";

        return damage;
    }
    
    void displayAttacks() {
        std::cout << "1. Basic attack.\n";
        std::cout << "2. Shield Bash.\n";
        std::cout << "3. Heavy Slash.\n";
    }
};

#endif