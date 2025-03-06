#include <iostream>
#include <iomanip>
#include <fstream>
#include <random>

using namespace std;

int main(int argc, char* argv[]) {
    ifstream input;
    ofstream output;
    string mat;

    if (argc != 2) {
        cout << "usage: " << argv[0] << " file\n";
        return -1;
    }

    input.open(argv[1]);
    if (!input) {
        cout << "I cannot open the input file\n";
        return -1;
    }

    while (input >> mat) {
        cout << mat << "\n";
    }

    input.close();

    return 0;
}

