#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "generator.h"


class Character {
protected:
    std::string name;
    int health, maxHealth;
    int strength;
    int armor;

    double criticalChance, criticalMultiplier;
    double missChance;

    bool stunned;
    int freezeTurns, poisonTurns;

    int skillCooldown1, skillCooldown2;
    int currentCooldown1, currentCooldown2;

public:
    Character() 
    : name("nomame"), health(0), maxHealth(0), strength(0), armor(0), criticalChance(0), 
      criticalMultiplier(0), missChance(0), stunned(false), freezeTurns(0), 
      poisonTurns(0), skillCooldown1(0), skillCooldown2(0), currentCooldown1(0), 
      currentCooldown2(0)
    {}

    Character(const Character &c)
    : name(c.name), health(c.health), maxHealth(c.maxHealth), strength(c.strength), 
      armor(c.armor), criticalChance(c.criticalChance), 
      criticalMultiplier(c.criticalMultiplier), missChance(c.missChance), 
      stunned(c.stunned), freezeTurns(c.freezeTurns), poisonTurns(c.poisonTurns), 
      skillCooldown1(c.skillCooldown1), skillCooldown2(c.skillCooldown2), 
      currentCooldown1(c.currentCooldown1), currentCooldown2(c.currentCooldown2)
    {}
    
    Character(std::string n, int mh, int s, int a, double cc, double cm, double mc, 
        int scd1, int scd2)
    : name(n), health(mh), maxHealth(mh), strength(s), armor(a), criticalChance(cc), 
      criticalMultiplier(cm), missChance(mc), stunned(false), freezeTurns(0), 
      poisonTurns(0), skillCooldown1(scd1), skillCooldown2(scd2), currentCooldown1(0), 
      currentCooldown2(0)
    {}

    std::string getName() {
        return name;
    }

    int getHealth() {
        return health;
    }

    int getStrenght() {
        return strength;
    }

    int getArmor() {
        return armor;
    }

    bool isAlive() {
        return (health > 0);
    }

    virtual int basicAttack() {
        double missRoll = Generator::randomNumber(1, 100) / 100.0;
        if (missRoll < missChance) {
            std::cout << name << " missed the attack!\n";
            return 0;
        }

        int damage = strength;
        double critRoll = Generator::randomNumber(1, 100) / 100.0;
        if (critRoll < criticalChance) {
            damage = damage * criticalMultiplier;
            std::cout << "Critical hit by " << name << "!\n";
        }

        return damage;
    }

    virtual void receiveDamage(int damage) {
        int finalDamage = damage - armor;
        if (finalDamage < 1) {
            finalDamage = 1;
        }

        health -= finalDamage;
        if (health < 0) {
            health = 0;
        }

        std::cout << name << " received " << finalDamage << " damage.\n";
        std::cout << "Current HP: " << health << "/" << maxHealth<< "\n";
    }

    virtual bool canUseSkill1() {
        return (currentCooldown1 == 0);
    }

    virtual bool canUseSkill2() {
        return (currentCooldown2 == 0);
    }

    void reduceCooldowns() {
        if (currentCooldown1 > 0) {
            currentCooldown1--;
        }

        if (currentCooldown2 > 0) {
            currentCooldown2--;
        }
    }

    void applyPoison(int turns) {
        poisonTurns = turns;
    }

    void applyFreeze(int turns) {
        freezeTurns = turns;
    }

    void applyStun() {
        stunned = true;
    }

    bool isStunned() {
        if (stunned) {
            stunned = false;
            return true;
        }
        return false;
    }

    bool isFrozen() {
        if (freezeTurns > 0) {
            int chance = Generator::randomNumber(1, 100);
            if (chance < 50) {
                freezeTurns--;
            } else {
                freezeTurns = 0;
            }
        }
        return false;
    }

    void applyStatVenomEffects() {
        if (poisonTurns > 0) {
            poisonTurns--;

            health -= 5;
            if (health < 0) {
                health = 0;
            }
            std::cout << name << " received 5 poison damage!\n";
        }
    }

    void heal(int amount) {
        if (amount < 0) {
            return;
        }

        health += amount;
        if (health > maxHealth) {
            health = maxHealth;
        }
    }

    virtual void displayStats() {
        std::cout << "\n===== " << name << " =====\n";
        std::cout << "HP: " << health << "/" << maxHealth << "\n";
        std::cout << "Strength: " << strength << "\n";
        std::cout << "Shield: " << armor << "\n\n";
    }

    virtual void performAction(std::vector<Character*> v) {
        if (isStunned()) {
            return;
        } 
        
        if (isFrozen()) {
            return;
        }

        applyStatVenomEffects();

        if (!isAlive()) {
            std::cout << name << " is dead\n";
            return;
        }

        reduceCooldowns();

        attack(v);
    }

    virtual int skillAttack1() = 0;
    virtual int skillAttack2() = 0;
    virtual void attack(std::vector<Character*>) = 0;
};

#endif