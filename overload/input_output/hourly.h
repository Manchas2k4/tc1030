#ifndef HOURLY_H
#define HOURLY_H

#include <iostream>
#include <sstream>
#include "employee.h"

using namespace std;

const float HOURSPERWEEK = 40;

class HourlyEmployee : public Employee {
private:
	float wage;
	float hours;
	
public:
	HourlyEmployee();
	HourlyEmployee(string i, string n, float w, float h);
	HourlyEmployee(const HourlyEmployee &he);
	float getWage() const;
	void setWage(float w);
	float getHours() const;
	void setHours(float h);
	string toString() const;
	float earnings() const;
};

HourlyEmployee::HourlyEmployee()
	: Employee(HOURLY, "nan", "name") {
	wage = 0;
	hours = 0;
}

HourlyEmployee::HourlyEmployee(string i, string n, float w, float h) 
	: Employee(HOURLY, i, n) {
	wage = w;
	hours = h;
}

HourlyEmployee::HourlyEmployee(const HourlyEmployee &he) 
	: Employee(HOURLY, he.id, he.name) {
	wage = he.wage;
	hours = he.hours;
}

float HourlyEmployee::getWage() const {
	return wage;
}

void HourlyEmployee::setWage(float w) {
	wage = w;
}

float HourlyEmployee::getHours() const {
	return hours;
}

void HourlyEmployee::setHours(float h) {
	hours = h;
}

string HourlyEmployee::toString() const {
	stringstream output;
	
	output << Employee::toString() << "\n" << "Hourly Wage: " << wage << "\n"
		   << "Hours Worked: " << hours;
	return output.str();
}

float HourlyEmployee::earnings() const {
	if (hours <= HOURSPERWEEK) {
		return (hours * wage);
	} else {
		return (HOURSPERWEEK * wage) + ((hours - 40) * wage * 1.5);
	}
}
ostream& operator<< (ostream &out, const HourlyEmployee &e) {
	out << e.getType() << "," << e.getId() << "," << e.getName() << "," << e.getWage() << "," << e.getHours();
	return out;
}

istream& operator>> (istream& in, HourlyEmployee &e) {
	string id, name;
	float wage, hours;
	
	cout << "Id: ";
	in >> id;
	in.ignore();
	e.setId(id);
	
	cout << "Name: ";
	in >> name;
	in.ignore();
	e.setName(name);
	
	cout << "Hourly wage: ";
	in >> wage;
	in.ignore();
	e.setWage(wage);
	
	cout << "Hours worked: ";
	in >> hours;
	in.ignore();
	e.setHours(hours);
	
	return in;
}

#endif