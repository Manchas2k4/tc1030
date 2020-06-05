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
	:Employee("SalariedEmployee", "nan", "noname") {
	weeklySalary = 0;
}
	
SalariedEmployee::SalariedEmployee(string i, string n, float ws)
	:Employee("SalariedEmployee", i, n) {
	weeklySalary = ws;
}
	
SalariedEmployee::SalariedEmployee(const SalariedEmployee &se)
	:Employee("SalariedEmployee", se.id, se.name) {
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

	return output.str();
}

float SalariedEmployee::earnings() const {
}

#endif