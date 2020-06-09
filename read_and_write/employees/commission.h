#ifndef COMMISSION_H
#define COMMISSION_H

#include <iostream>
#include <sstream>
#include "employee.h"

using namespace std;

class CommissionEmployee : public Employee {
private:
	float grossSales;
	float commissionRate;
	
public:
	CommissionEmployee();
	CommissionEmployee(string i, string n, float gs, float cr);
	CommissionEmployee(const CommissionEmployee &ce);
	float getGrossSales() const;
	void setGrossSales(float gs);
	float getCommissionRate() const;
	void setCommissionRate(float cr);
	string toString() const;
	float earnings() const;
};

CommissionEmployee::CommissionEmployee()
	: Employee(COMMISSION, "nan", "name") {
	grossSales = 0;
	commissionRate = 0;
}

CommissionEmployee::CommissionEmployee(string i, string n, float gs, float cr) 
	: Employee(COMMISSION, i, n) {
	grossSales = gs;
	commissionRate = cr;
}

CommissionEmployee::CommissionEmployee(const CommissionEmployee &ce) 
	: Employee(COMMISSION, ce.id, ce.name) {
	grossSales = ce.grossSales;
	commissionRate = ce.commissionRate;
}

float CommissionEmployee::getGrossSales() const {
	return grossSales;
}

void CommissionEmployee::setGrossSales(float gs) {
	grossSales = gs;
}

float CommissionEmployee::getCommissionRate() const {
	return commissionRate;
}

void CommissionEmployee::setCommissionRate(float cr) {
	commissionRate = cr;
}

string CommissionEmployee::toString() const {
	stringstream output;
	
	output << Employee::toString() << "," << grossSales << "," << commissionRate;
	return output.str();
}

float CommissionEmployee::earnings() const {
	return grossSales * commissionRate;
}

#endif