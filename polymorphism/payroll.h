#ifndef PAYROLL_H
#define PAYROLL_H

#include <iostream>
#include <sstream>

using namespace std;

const int SIZE = 100;

class Payroll {
private:
	Employee* employees[SIZE];
	int count;
	
public:
	Payroll();
	~Payroll();
	bool addEmployee(Employee *e);
	string toString() const;
	float calculatePayroll() const;
	int countSalariedEmployees() const;
	Employee* lookUpEmployeeInfo(string id) const;
	Employee* searchEmployeeWithMoreHours() const;
};

Payroll::Payroll() {
}

Payroll::~Payroll() {
}	

bool Payroll::addEmployee(Employee *e) {
	return false;
}

string Payroll::toString() const {
	stringstream output;
	
	return output.str();
}

float Payroll::calculatePayroll() const {
	return 0;
}

int Payroll::countSalariedEmployees() const {
	return 0;
}

Employee* Payroll::lookUpEmployeeInfo(string id) const {
	return NULL;
}

Employee* Payroll::searchEmployeeWithMoreHours() const {
	return NULL;
}
#endif