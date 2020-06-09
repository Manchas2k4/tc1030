#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <sstream>

using namespace std;

typedef unsigned int uint;

const uint EMPLOYEE = 0;
const uint SALARIED = 1;
const uint HOURLY = 2;
const uint COMMISSION = 3;

class Employee {
protected:
	uint type;
	string id, name;
	
public:
	Employee();
	Employee(int t, string i, string n);
	Employee(const Employee &e);
	uint getType() const;
	string getId() const;
	void setId(string i);
	string getName() const;
	void setName(string n);
	virtual string toString() const;
	virtual float earnings() const = 0;
};

Employee::Employee() {
	type = EMPLOYEE;
	id = "nan";
	name = "noname";
}

Employee::Employee(int t, string i, string n) {
	type = t;
	id = i;
	name = n;
}

Employee::Employee(const Employee &e) {
	type = e.type;
	id = e.id;
	name = e.name;
}

uint Employee::getType() const {
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
	
	output << type << "," << id << "," << name;
	return output.str();
}


#endif
