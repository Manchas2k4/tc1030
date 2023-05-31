#include <iostream>
#include <iomanip>

using namespace std;

void display() {
    cout << "hola\n";
    return;
    cout << "adios\n";
}

int main(int argc, char* argv[]) {
    for (int i = 0; i < argc; i++) {
        cout << "argv[" << i << "] :" << argv[i] << "\n";
    }

    display();
    return 0;
}

