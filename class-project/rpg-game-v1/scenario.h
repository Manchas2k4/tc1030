#ifndef SCENARIO_H
#define SCENARIO_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

class Scenario {
private:
    std::string title, won, loose;

public:
    Scenario() 
    : title(""), won(""), loose("")
    {}
    
    Scenario(std::string filename) {
        std::ifstream file(filename);
        getline(file, title);
        getline(file, won);
        getline(file, loose);
        file.close();
    }

    Scenario(const Scenario &s) 
    : title(s.title), won(s.won), loose(s.loose)
    {}

    bool hasWon() {
        return false;
    }

    void execute() {
        std::cout << title << "\n\n";
        std::cout << won << "\n\n";
        std::cout << loose << "\n\n";
    }
};

#endif