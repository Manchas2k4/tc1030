#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <algorithm>
#include <random>
#include "generator.h"
#include "scenario.h"
#include "console.h"
#include "character.h"
#include "hero.h"
#include "warrior.h"
#include "archer.h"
#include "wizard.h"
#include "enemy.h"

using namespace std;

void creatingHeroes(vector<Character*> &heroes) {
    string name;
    int option;

    heroes.resize(2);
    for (int i = 0; i < heroes.size(); i++) {
        cout << "(" << i << ")" << " Hero's name? ";
        cin >> name;
        cout << "Hero class?\n";
        cout << "1. Warrior\n";
        cout << "2. Archer\n";
        cout << "3. Wizard\n";
        option = Console::validateIntegerInRange("Option? ", 1, 3);

        switch(option) {
            case 1 : heroes[i] = new Warrior(name); break;
            case 2 : heroes[i] = new Archer(name); break;
            default: heroes[i] = new Wizard(name); break;
        }
    }
}

int main(int argc, char* argv[]) {
    /*
    

    
    

    vector<Character*> heroes(2);
    heroes[0] = new Warrior("Warrior1");
    heroes[1] = new Archer("Archer1");
    
    Scenario scene;
    try {
        scene = Scenario("scenarios/scenario01.txt", heroes);
        scene.execute();
    } catch (const std::exception &e) {
        cout << "Error: " << e.what() << "\n";
    }
    */
    vector<Character*> heroes;
    vector<Scenario> scenarios;

    creatingHeroes(heroes);

    scenarios.resize(6);
    for (int i = 0; i < scenarios.size(); i++) {
        stringstream filename;
        filename << "scenarios/scenario0" << (i + 1) << ".txt";
        try {
            scenarios[i] = Scenario(filename.str(), heroes);
        } catch (const std::exception &e) {
            cout << "Error: " << e.what() << "\n";
        }
    }
    random_device rd;
    mt19937 gen(rd());
    shuffle(scenarios.begin(), scenarios.end(), gen);

    int i = 0;
    while (i < scenarios.size()) {
        scenarios[i].execute();
        if (!scenarios[i].heroesWon()) {
            break;
        }
        i++;
    }

    return 0;
}