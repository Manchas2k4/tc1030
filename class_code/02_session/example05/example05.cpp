#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

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
};

Person::Person() : name(string("noname")), age(0) {}

Person::Person(string n, int a) : name(n), age(a) {}

Person::Person(const Person &p) : name(p.name), age(p.age) {}

string Person::getName() const { return name; }

int Person::getAge() const { return age; }

int main(int argc, char* argv[]) {
    vector<Person> v;
    ifstream file;
    string name;
    int age, amount;

    if (argc != 2) {
        cout << "usage: " << argv[0] << " file\n";
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
        file >> name >> age;
        v[i] = Person(name, age);
    }

    file.close();

    Person p(string("noname"), 10000);
    for (int i = 0; i < amount; i++) {
        if (p.getAge() > v[i].getAge()) {
            p = v[i];
        }
    }
    cout << p.getName() << " " << p.getAge() << "\n";

    return 0;
}