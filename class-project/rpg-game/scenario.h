#ifndef SCENARIO_H
#define SCENARIO_H

#include <iostream>
#include <string>
#include <fstream>

class Scenario {
private:
    std::string title, description, win, loose;

public:
    Scenario()
      : title(""), description(""), win(""), loose("")
    {}

    Scenario(std::string filename) {
        std::ifstream file(filename);

        if (!file.is_open()) {
            throw std::runtime_error("Could not open file: " + filename);
        }

        if (!getline(file, title) ||
            !getline(file, description) ||
            !getline(file, win) ||
            !getline(file, loose)) {
            throw std::runtime_error("Invalid scenario format in file: " + filename);
        }

        file.close();
    }

    Scenario(const Scenario &s) 
      : title(s.title), description(s.description), win(s.win), loose(s.loose)
    {}

    void execute() {
        std::cout << title << "\n";
        std::cout << description << "\n";
    }
};

#endif