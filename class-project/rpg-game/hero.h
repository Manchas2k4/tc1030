#ifndef HERO_H
#define HERO_H

#include "character.h"
#include "console.h"

class Hero : public Character {
protected:
    int mana, maxMana, manaRegeneration;
    int manaCost1, manaCost2;

public:
    Hero() 
    : Character(), mana(0), maxMana(0), manaRegeneration(0), manaCost1(0), manaCost2(0)
    {}

    Hero(const Hero &h)
    : Character(h), mana(h.mana), maxMana(h.maxMana), manaRegeneration(h.manaRegeneration), 
      manaCost1(h.manaCost1), manaCost2(h.manaCost2)
    {}
    
    Hero(std::string n, int mh, int s, int a, double cc, double cm, double mc, int scd1, 
        int scd2, int mm, int mr, int mc1, int mc2)
    : Character(n, mh, s, a, cc, cm, mc, scd1, scd2), mana(mm), maxMana(mm), 
      manaRegeneration(mr), manaCost1(mc1), manaCost2(mc2)
    {}

    int getMana() {
        return mana;
    }

    void restoreMana(int amount) {
        if (amount < 0) {
            return;
        }

        mana += amount;
        if (mana > maxMana) {
            mana = maxMana;
        }
    }

    bool useMana(int amount) {
        if (mana < amount) {
            return false;
        }

        mana -= amount;
        return true;
    }

    bool canUseSkill1() override {
        return (currentCooldown1 == 0 && mana >= manaCost1);
    }

    bool canUseSkill2() override {
        return (currentCooldown2 == 0 && mana >= manaCost2);
    }

    void displayStats() override {
        std::cout << "\n===== " << name << " =====\n";
        std::cout << "HP: " << health << "/" << maxHealth << "\n";
        std::cout << "Mana: " << mana << "/" << maxMana << "\n";
        std::cout << "Strength: " << strength << "\n";
        std::cout << "Shield: " << armor << "\n\n";
    }

    virtual void attack(std::vector<Character*> v) {
        std::cout << "Which enemy do you want to attack?\n";
        for (int i = 0; i < v.size(); i++) {
            std::cout << i << ": ";
            v[i]->displayStats();
        }
        int enemy = Console::validateIntegerInRange("Option? ", 0, v.size() - 1);

        if (!v[enemy]->isAlive()) {
            std::cout << "You cannot attack this enemy because it is already dead. Your attack is wasted.\n";
            return;
        }

        std::cout << "Which attack do you want to perform?\n";
        displayAttacks();
        int attack = Console::validateIntegerInRange("Option? ", 1, 3);

        int damage = 0;
        switch(attack) {
            case 1 : 
                damage = basicAttack();
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
    }

    void performAction(std::vector<Character*> v) override {
        Character::performAction(v);
        restoreMana(manaRegeneration);
    }

    virtual void displayAttacks() = 0;
};

#endif