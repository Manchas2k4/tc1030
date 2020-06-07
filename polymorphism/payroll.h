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
	count = 0;
}

Payroll::~Payroll() {
	for (int i = 0; i < count; i++) {
		delete employees[i];
	}
	count = 0;
}	

bool Payroll::addEmployee(Employee *e) {
	if (count < SIZE) {
		employees[count] = e;
		count++;
		return true;
	}
	return false;
}

string Payroll::toString() const {
	stringstream output;
	
	for (int i = 0; i < count; i++) {
		output << employees[i]->toString() << "\n";
	}
	return output.str();
}

float Payroll::calculatePayroll() const {
	float acum = 0;
	for (int i = 0; i < count; i++) {
		acum += employees[i]->earnings();
	}
	return acum;
}

int Payroll::countSalariedEmployees() const {
	int acum = 0;
	for (int i = 0; i < count; i++) {
		if (employees[i]->getType() == "SalariedEmployee") {
			acum++;
		}
	}
}

Employee* Payroll::lookUpEmployeeInfo(string id) const {
	for (int i = 0; i < count; i++) {
		if (employees[i]->getId() == id) {
			return employees[i];
		}
	}
	return NULL;
}

Employee* Payroll::searchEmployeeWithMoreHours() const {
	HourlyEmployee* max = NULL;
	for (int i = 0; i < count; i++) {
		if (employees[i]->getType() == "HourlyEmployee") {
			HourlyEmployee* aux = (HourlyEmployee*) employees[i];
			if (max == NULL) {
				max = aux;
			} else if (max->getHours() < aux->getHours()) {
				max = aux;
			}
		}
	}
	return max;
}
#endif