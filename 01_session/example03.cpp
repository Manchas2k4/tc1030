#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 100;

void swap(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
    cout << "swap a(x) = " << a << " b(y) = " << b << "\n";
}

long sumatoria(int sup) {
    long acum = 0;
    for (int i = 1; i <= sup; i++) {
        acum += i;
    }
    return acum;
}

long sumatoria(int inf, int sup) {
    long acum = 0;
    for (int i = inf; i <= sup; i++) {
        acum += i;
    }
    return acum;
}

int main(int argc, char* argv[]) {
    int x, y;

    x = 10;
    y = 20;

    cout << "before x = " << x << " y = " << y << "\n";
    swap(x, y);
    cout << "after x = " << x << " y = " << y << "\n";

    cout << "sumatoria(100): " << sumatoria(100) << "\n";
    cout << "sumatoria(50, 100): " << sumatoria(50, 100) << "\n";

    return 0;
}

