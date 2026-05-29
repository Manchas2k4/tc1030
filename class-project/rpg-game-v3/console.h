#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <sstream>
#include <limits>
#include <vector>
#include <algorithm>

class Console {
private:
    static int readInputWithRange(const std::string &text, int min, int max) {
        int input;

        if (min > max) {
            std::swap(min, max);
        }

        std::cout << text;
        if (!(std::cin >> input)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::runtime_error("Invalid input type. Please enter an integer.");
        }

        std::stringstream message;
        if (input < min) {
            message << "The input must be greater than or equal to " << min << ".";
            throw std::invalid_argument(message.str());
        }

        if (input > max) {
            message << "The input must be less than or equal to " << max << ".";
            throw std::out_of_range(message.str());
        }

        return input;
    }

    static char readCharInValidSet(const std::string &text, 
        const std::vector<char> &validChars) {
        
        char input;

        std::cout << text;
        if (!(std::cin >> input)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::runtime_error("Invalid input type. Please enter a character.");
        }

        auto it = std::find(validChars.begin(), validChars.end(), input);
        if (it == validChars.end()) {
            std::stringstream message;
            message << "Invalid option. Valid characters are: ";
            for (char c : validChars) {
                message << c << ' ';
            }
            throw std::invalid_argument(message.str());
        }

        return input;
    }

public:
    static int validateIntegerInRange(const std::string &text, int min, int max) {
        int answer;

        while (true) {
            try {
                answer = Console::readInputWithRange(text, min, max);
                break;
            } catch (const std::exception &e) {
                std::cout << "Error: " << e.what() << "\n";
            }
        }

        return answer;
    }

    static char validCharOption(const std::string &text, const std::vector<char> &validChars) {
        char answer;

        while (true) {
            try {
                answer = Console::readCharInValidSet(text, validChars);
                break;
            } catch (const std::exception &e) {
                std::cout << "Error: " << e.what() << "\n";
            }
        }

        return answer;
    }

    static void waitForInput() {
        std::cout << "Presiona ENTER para continuar...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }
};

#endif