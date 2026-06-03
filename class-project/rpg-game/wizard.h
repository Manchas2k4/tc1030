#ifndef WIZARD_H
#define WIZARD_H

#include "hero.h"

class Wizard : public Hero {
private:
    int adittionalManaRegeneration;

public:
    Wizard() 
    : Hero(), adittionalManaRegeneration(5)
    {}

    Wizard(const Wizard &w)
    : Hero(w), adittionalManaRegeneration(5)
    {}
    
    Wizard(std::string n)
    : Hero(n, 70, 8, 3, 0.20, 2.5, 0.15, 2, 5, 120, 8, 20, 25), adittionalManaRegeneration(5)
    {}

    void performAction(std::vector<Character*> v) override {
        restoreMana(adittionalManaRegeneration);
        std::cout << name << " restored " << adittionalManaRegeneration << " mana.\n";
        Hero::performAction(v);
    }

    int skillAttack1() override {
        if (!canUseSkill1()) {
            std::cout << "Skill unavailable!\n";
            return 0;
        }

        int damage = 18;
        useMana(manaCost1);
        currentCooldown1 = skillCooldown1;
        std::cout << name << " used Ice Storm!\n";

        return damage;
    }

    int skillAttack2() override {
        if (!canUseSkill2()) {
            std::cout << "Skill unavailable!\n";
            return 0;
        }

        int damage = 28;
        useMana(manaCost2);
        currentCooldown2 = skillCooldown2;
        std::cout << name << " used Fireball!\n";

        return damage;
    }

    void displayAttacks() {
        std::cout << "1. Basic attack.\n";
        std::cout << "2. Ice Storm.\n";
        std::cout << "3. Fireball.\n";
    }
};

#endif