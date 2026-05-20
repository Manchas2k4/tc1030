#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <sstream>
#include <limits>
#include <vector>
#include <algorithm>

/**
 * @class Validator
 * @brief A utility class for input validation.
 * 
 * This class provides static methods to validate user input, ensuring it falls
 * within a specified range or matches a set of valid options. It handles invalid
 * input gracefully by prompting the user until valid input is provided.
 */
class Validator {
private:
    /**
     * @brief Reads and validates an integer input within a specified range.
     * 
     * This method prompts the user for an integer input and ensures it falls 
     * within the range [min, max]. If the input is invalid (non-integer or 
     * out of range), an exception is thrown.
     * 
     * @param text The prompt text to display to the user.
     * @param min The minimum valid value for the input.
     * @param max The maximum valid value for the input.
     * @return A valid integer within the range [min, max].
     * 
     * @throws std::runtime_error If the input is not an integer.
     * @throws std::invalid_argument If the input is less than the minimum value.
     * @throws std::out_of_range If the input is greater than the maximum value.
     */
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

    /**
     * @brief Reads and validates a character input from a set of valid options.
     * 
     * This method prompts the user for a character input and ensures it matches
     * one of the valid characters provided. If the input is invalid (non-character
     * or not in the valid set), an exception is thrown.
     * 
     * @param text The prompt text to display to the user.
     * @param validChars A vector of valid character options.
     * @return A valid character from the set of valid options.
     * 
     * @throws std::runtime_error If the input is not a character.
     * @throws std::invalid_argument If the input is not in the valid character set.
     */
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
    /**
     * @brief Validates and returns an integer input within a specified range.
     * 
     * This method repeatedly prompts the user until a valid integer within the
     * range [min, max] is entered. It handles exceptions and provides error messages
     * for invalid inputs.
     * 
     * @param text The prompt text to display to the user.
     * @param min The minimum valid value for the input.
     * @param max The maximum valid value for the input.
     * @return A valid integer within the range [min, max].
     */
    static int validateIntegerInRange(const std::string &text, int min, int max) {
        int answer;

        std::cout << "pre while\n";
        while (true) {
            try {
                answer = Validator::readInputWithRange(text, min, max);
                break;
            } catch (const std::exception &e) {
                std::cout << "Error: " << e.what() << "\n";
            }
        }

        return answer;
    }

    /**
     * @brief Validates and returns a character input from a set of valid options.
     * 
     * This method repeatedly prompts the user until a valid character from the
     * provided set of valid options is entered. It handles exceptions and provides
     * error messages for invalid inputs.
     * 
     * @param text The prompt text to display to the user.
     * @param validChars A vector of valid character options.
     * @return A valid character from the set of valid options.
     */
    static char validCharOption(const std::string &text, const std::vector<char> &validChars) {
        char answer;

        while (true) {
            try {
                answer = Validator::readCharInValidSet(text, validChars);
                break;
            } catch (const std::exception &e) {
                std::cout << "Error: " << e.what() << "\n";
            }
        }

        return answer;
    }
};

#endif