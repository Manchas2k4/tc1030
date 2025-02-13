#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    ifstream file;
    vector<int> v;
    int amount, acum;
    double avg;

    if (argc != 2) {
        cout << "usage: " << argv[0] << " filename\n";
        return -1;
    }

    file.open(argv[1]);
    if (!file) {
        cout << "I cannot open the file\n";
        return -1;
    }

    file >> amount;
    v.resize(amount);

    for (int i = 0; i < amount; i++) {
        file >> v[i];
    }

    /*
    acum = 0;
    for (int number : v) {
        acum += number;
    }
    */

    acum = 0;
    for (int i = 0; i < amount; i++) {
        acum += v[i];
    }
    cout << "average: " << (acum / amount) << "\n";

    return 0;
}