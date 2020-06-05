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
	: Employee("HourlyEmployee", "nan", "name") {
	wage = 0;
	hours = 0;
}

HourlyEmployee::HourlyEmployee(string i, string n, float w, float h) 
	: Employee("HourlyEmployee", i, n) {
	wage = w;
	hours = h;
}

HourlyEmployee::HourlyEmployee(const HourlyEmployee &he) 
	: Employee("HourlyEmployee", he.id, he.name) {
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

	return output.str();
}

float HourlyEmployee::earnings() const {
}

#endif