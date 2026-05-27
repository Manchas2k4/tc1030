#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 100; //1e9

int multiplosCinco(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 5 == 0) {
            count++;
        }
    }
    return count;
}

int pares(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

int mayoresA7(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 7) {
            count++;
        }
    }
    return count;
}

int counting(int arr[], int size, bool (*fn) (int)) {
    int count = 0; 
    for (int i = 0; i < size; i++) {
        if ( fn(arr[i]) ) {
            count++;
        }
    }
    return count;
}

bool cinco(int val) {
    return (val % 5 == 0);
}

bool mayor7 (int val) {
    return (val > 7);
}

int main(int argc, char *argv[]) {
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        arr[i] = (i + 1);
    }

    cout << "Multiplos de 5: " << multiplosCinco(arr, SIZE) << "\n";
    cout << "Multiplos de 5: " << counting(arr, SIZE, cinco) << "\n";

    cout << "Mayor a 7: " << mayoresA7(arr, SIZE) << "\n";
    cout << "Mayor a 7: " << counting(arr, SIZE, mayor7) << "\n";
    return 0;
}