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
	
	output << Employee::toString() << "\n" << "Gross Sales: " << grossSales << "\n"
		   << "Commission Rate: " << commissionRate;
	return output.str();
}

float CommissionEmployee::earnings() const {
	return grossSales * commissionRate;
}

ostream& operator <<(ostream &out, const CommissionEmployee &e) {
	out << e.getType() << "," << e.getId() << "," << e.getName() << "," << e.getGrossSales() << "," << e.getCommissionRate();
	return out;
}

istream& operator>> (istream& in, CommissionEmployee &e) {
	string id, name;
	float grossSales, commissionRate;
	
	cout << "Id: ";
	in >> id;
	in.ignore();
	e.setId(id);
	
	cout << "Name: ";
	in >> name;
	in.ignore();
	e.setName(name);
	
	cout << "Gross Sales: ";
	in >> grossSales;
	in.ignore();
	e.setGrossSales(grossSales);
	
	cout << "Hours worked: ";
	in >> commissionRate;
	in.ignore();
	e.setCommissionRate(commissionRate);
	
	return in;
}

#endif