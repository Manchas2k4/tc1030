#ifndef SCENARIO_H
#define SCENARIO_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include "character.h"
#include "hero.h"
#include "enemy.h"
#include "goblin.h"
#include "console.h"

class Scenario {
private:
    std::string title, description, winningResult, losingResult;
    std::vector<Character*> heroes, enemies, characters;
    bool win;

public:
    Scenario()
      : title(""), description(""), winningResult(""), losingResult(""), win(false)
    {}

    Scenario(std::string filename, std::vector<Character *> &v) {
        std::ifstream file(filename);

        if (!file.is_open()) {
            throw std::runtime_error("Could not open file: " + filename);
        }

        if (!getline(file, title) ||
            !getline(file, description) ||
            !getline(file, winningResult) ||
            !getline(file, losingResult)) {
            throw std::runtime_error("Invalid scenario format in file: " + filename);
        }

        file.close();

        if (v.size() != 2) {
            throw std::invalid_argument("The party must contain exactly 2 heroes.");
        }

        win = false;

        heroes = std::vector<Character*>(v);

        enemies.resize(3);
        enemies[0] = new Goblin("Goblin Raider 1");
        enemies[1] = new Goblin("Goblin Raider 2");
        enemies[2] = new Goblin("Goblin Raider 3");

        characters.resize(5);
        int j = 0;
        for (int i = 0; i < heroes.size(); i++) {
            characters[j++] = heroes[i];
        }
        for (int i = 0; i < enemies.size(); i++) {
            characters[j++] = enemies[i];
        }

        std::random_device rd;
        std::mt19937 gen(rd());
        shuffle(characters.begin(), characters.end(), gen);
    }

    Scenario(const Scenario &s) 
      : title(s.title), description(s.description), winningResult(s.winningResult), 
        losingResult(s.losingResult), win(s.win), characters(s.characters), heroes(s.heroes),
        enemies(s.enemies)
    {}

    bool heroesDefeated() {
        for (int i = 0; i < heroes.size(); i++) {
            if (heroes[i]->isAlive()) {
                return false;
            }
        }
        return true;
    }

    bool enemiesDefeated() {
        for (int i = 0; i < enemies.size(); i++) {
            if (enemies[i]->isAlive()) {
                return false;
            }
        }
        return true;
    }

    bool heroesWon() {
        return (win == true);
    }

    void execute() {
        std::cout << "\n===== " << title << " =====\n";
        std::cout << description << "\n";
        Console::waitForInput();

        while (!heroesDefeated() && !enemiesDefeated()) {
            for (int i = 0; i < characters.size(); i++) {
                if (characters[i]->isAlive()) {
                    std::cout << "\n===== Attacking " << characters[i]->getName() << " =====\n";
                    if(dynamic_cast<Enemy*>(characters[i])) {
                        characters[i]->performAction(heroes);
                    } else if(dynamic_cast<Hero*>(characters[i])) {
                        characters[i]->displayStats();
                        characters[i]->performAction(enemies);
                    }
                    Console::waitForInput();   
                }
            }
        }

        win = !heroesDefeated();
        if (win) {
            std::cout << "\n" << winningResult << "\n";
        } else {
            std::cout << "\n" << losingResult << "\n";
        }
        Console::waitForInput();
    }
};

#endif