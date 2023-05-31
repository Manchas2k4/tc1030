#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    vector<int> data;
    ifstream file;
    string filename;
    int n, acum;

    cout << "filename: ";
    cin >> filename;

    file.open(filename);
    if (!file) {
        cout << "File does not exist\n";
        return -1;
    }

    file >> n;
    data.resize(n);

    for (int i = 0; i < n; i++) {
        file >> data[i];
    }

    acum = 0;
    for (int i = 0; i < data.size(); i++) {
        acum += data[i];
    }
    cout << "average = " << setprecision(2) << fixed 
         << ((float) acum / data.size()) << "\n";



    return 0;
}













