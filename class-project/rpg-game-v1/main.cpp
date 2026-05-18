#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream> 
#include <algorithm>
#include <random>
#include "scenario.h"

using namespace std;

int main(int argc, char* argv[]) {
    vector<Scenario> scenarios;

    scenarios.resize(6);
    for (int i = 0; i < scenarios.size(); i++) {
        std::stringstream filename;
        filename << "scenarios/scenario0" << (i + 1) << ".txt";
        scenarios[i] = Scenario(filename.str());
    }

    random_device rd;
    mt19937 g(rd());
    shuffle(scenarios.begin(), scenarios.end(), g);

    for (Scenario s : scenarios) {
        s.execute();
        cout << "\n\n";
    }

    return 0;
}