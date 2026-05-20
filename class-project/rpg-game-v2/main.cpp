#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <algorithm>
#include <random>
#include "generator.h"
#include "scenario.h"
#include "validator.h"

using namespace std;

int main(int argc, char* argv[]) {
    /*
    Scenario s;

    try {
        s = Scenario("scenario.txt");
        cout << "The file has been read\n";
    } catch (const std::exception &e) {
        cout << "Error: " << e.what() << "\n";
    }

    try {
        s = Scenario("scenarios/bad_scenario.txt");
        cout << "The file has been read\n";
    } catch (const std::exception &e) {
        cout << "Error: " << e.what() << "\n";
    }
    */

    /*
    int answer;
    while(true) {
        try {
            answer = Validator::readInputWithInRange("Dame un numero entre 1 y 5: ", 1, 5);
            break;
        } catch (const std::exception &e) {
            cout << "Error: " << e.what() << "\n";
        }
    }
    cout << "Tu respuesta fue: " << answer << "\n";
    */

    vector<Scenario> scenarios;

    scenarios.resize(6);
    for (int i = 0; i < scenarios.size(); i++) {
        stringstream filename;
        filename << "scenarios/scenario0" << (i + 1) << ".txt";
        try {
            scenarios[i] = Scenario(filename.str());
        } catch (const std::exception &e) {
            cout << "Error: " << e.what() << "\n";
        }
    }

    random_device rd;
    mt19937 gen(rd());
    shuffle(scenarios.begin(), scenarios.end(), gen);

    int i = 0;
    char answer;
    while (i < scenarios.size()) {
        scenarios[i].execute();
        
        answer = Validator::validCharOption("Continue (y/n)? ", {'y', 'n'});

        if (answer == 'n') {
            break;
        }

        i++;
    }
}