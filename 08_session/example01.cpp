#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[]) {
    int number;

    while (1) {
        cout << "Give me a number between 1 and 100 ";
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

    return 0;
}