#ifndef SALARIED_H
#define SALARIED_H

#include <iostream>
#include <sstream>
#include "employee.h"

using namespace std;

class SalariedEmployee : public Employee {
protected:
	float weeklySalary;
	
public:
	SalariedEmployee();
	SalariedEmployee(string i, string n, float ws);
	SalariedEmployee(const SalariedEmployee &se);
	float getWeeklySalary() const;
	void setWeeklySalary(float ws);
	string toString() const;
	float earnings() const;
};

SalariedEmployee::SalariedEmployee()
	:Employee(SALARIED, "nan", "noname") {
	weeklySalary = 0;
}
	
SalariedEmployee::SalariedEmployee(string i, string n, float ws)
	:Employee(SALARIED, i, n) {
	weeklySalary = ws;
}
	
SalariedEmployee::SalariedEmployee(const SalariedEmployee &se)
	:Employee(SALARIED, se.id, se.name) {
	weeklySalary = se.weeklySalary;
}
	
float SalariedEmployee::getWeeklySalary() const {
	return weeklySalary;
}

void SalariedEmployee::setWeeklySalary(float ws) {
	weeklySalary = ws;
}

string SalariedEmployee::toString() const {
	stringstream output;
	
	output << Employee::toString() << "," << weeklySalary;
	return output.str();
}

float SalariedEmployee::earnings() const {
	return weeklySalary;
}
#endif