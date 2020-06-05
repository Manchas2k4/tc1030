#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <sstream>

using namespace std;

class Employee {
protected:
	string id, name, type;
	
public:
	Employee();
	Employee(string t, string i, string n);
	Employee(const Employee &e);
	string getType() const;
	string getId() const;
	void setId(string i);
	string getName() const;
	void setName(string n);
	virtual string toString() const;
	virtual float earnings() const = 0;
};

Employee::Employee() {
	type = "none";
	id = "nan";
	name = "noname";
}

Employee::Employee(string t, string i, string n) {
	type = t;
	id = i;
	name = n;
}

Employee::Employee(const Employee &e) {
	type = e.type;
	id = e.id;
	name = e.name;
}

string Employee::getType() const {
	return type;
}

string Employee::getId() const {
	return id;
}

void Employee::setId(string i) {
	id = i;
}

string Employee::getName() const {
	return name;
}

void Employee::setName(string n) {
	name = n;
}

string Employee::toString() const {
	stringstream output;
	
	output << "Id : " << id << "\n" << "Name: " << name;
	return output.str();
}

#endif
