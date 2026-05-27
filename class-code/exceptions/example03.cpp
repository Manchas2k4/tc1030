#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

int read_input() {
    int number;

    while (1) {
        cout << "Give me a number ";
        cin >> number;
        try {
            if (number < 1 || number > 100) {
                throw (number);
            }
            break;
        } catch (int input) {
            cout << input << " is not between 1 a 100, try again\n";
        }
    }
    return number;
}

int main(int argc, char* argv[]) {
    default_random_engine generator;
	uniform_int_distribution<int> distribution(1, 100);
    int numberToGuess, number;
    bool finished;

    generator.seed(12345);
    numberToGuess = distribution(generator);
    finished = false;

    cout << "Guess a name between 1 a 100\n";
    while (!finished) {
        number = read_input();
        if (number == numberToGuess) {
            cout << "You win!\n";
            finished = true;
        } else if (number < numberToGuess) {
            cout << number << " is low\n";
        } else {
            cout << number << " is high\n";
        }
    }
    return 0;
}