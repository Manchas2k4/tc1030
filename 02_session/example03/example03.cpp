#include <iostream>
#include <iomanip>
#include <fstream>
#include <random>

using namespace std;

string names[2] = {"comms", "ships"};

int main(int argc, char* argv[]) {
    ifstream input;
    ofstream output;
    string mat;
    int project, amount;
    default_random_engine generator;
    uniform_int_distribution<int> distribution(1,100);

    if (argc != 3) {
        cout << "usage: " << argv[0] << " input-file output-file\n";
        return -1;
    }

    input.open(argv[1]);
    if (!input) {
        cout << "I cannot open the input file\n";
        return -1;
    }

    output.open(argv[2]);
    if (!output) {
        cout << "I cannot open the output file\n";
        return -1;
    }

    input >> amount;

    for (int i = 0; i < amount; i++) {
        input >> mat;
        project = (distribution(generator) % 2); 
        output << mat << "," << names[project] << "\n"; 
    }

    input.close();
    output.close();

    return 0;
}

