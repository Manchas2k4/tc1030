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
                throw ("The input es incorrect. Please try again");
            }
            break;
        } catch (const char* error) {
            cout << error  << "\n";
        }
    }

    return 0;
}