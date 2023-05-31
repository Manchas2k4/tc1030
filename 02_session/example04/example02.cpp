#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person();
    Person(string, int);
    Person(const Person&);

    string getName() const;
    int getAge() const;

    void setName(string);
    void setAge(int);
};

Person::Person() {
    name = "None";
    age = 0;
}

Person::Person(string n, int a) {
    name = n;
    age = a;
}

Person::Person(const Person &other) {
    name = other.name;
    age = other.age;
}

string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

void Person::setName(string n) {
    name = n;
}

void Person::setAge(int a) {
    age = a;
}


int main(int argc, char* argv[]) {
    vector<Person> data;
    int n, age;
    string name, filename;
    int lower, upper;
    float acum;
    ifstream inputFile;
    ofstream outputFile("salida.txt");

    cout << "filename: ";
    cin >> filename;

    inputFile.open(filename);
    if (!inputFile) {
        cout << "File not found\n";
        return -1;
    }

    inputFile >> n;
    data.resize(n);

    for (int i = 0; i < data.size(); i++) {
        inputFile >> name >> age;
        data[i] = Person(name, age);
    }

    lower = 0;
    upper = 0;
    acum = 0.0;
    for (int i = 0; i < data.size(); i++) {
        if (data[i].getAge() < data[lower].getAge()) {
            lower = i;
        }
        if (data[i].getAge() > data[upper].getAge()) {
            upper = i;
        }
        acum += data[i].getAge();
    }

    outputFile << "Oldest: " << data[upper].getName() 
               << "," << data[upper].getAge() << "\n";

    outputFile << "Youngest: " << data[lower].getName() 
               << "," << data[lower].getAge() << "\n";

    outputFile << "Average: " << setprecision(2) << fixed   
               << (acum / data.size()) << "\n";

    inputFile.close();
    outputFile.close();
    return 0;
}