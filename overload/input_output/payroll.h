#ifndef PAYROLL_H
#define PAYROLL_H

#include <iostream>
#include <sstream>
#include <fstream>
#include "employee.h"
#include "salaried.h"
#include "hourly.h"
#include "commission.h"
#include "utility.h"

using namespace std;

const uint MAXIMUM = 100;

class Payroll {
private:
	Employee* employees[MAXIMUM];
	uint count;
	
public:
	Payroll();
	~Payroll();
	bool addEmployee(Employee *e);
	string toString() const;
	float calculatePayroll() const;
	int countSalariedEmployees() const;
	Employee* lookUpEmployeeInfo(string id) const;
	Employee* searchEmployeeWithMoreHours() const;
	
	bool savePayroll(string filename) const;
	bool loadPayroll(string filename);
};

Payroll::Payroll() {
	count = 0;
}

Payroll::~Payroll() {
	for (uint i = 0; i < count; i++) {
		delete employees[i];
	}
	count = 0;
}	

bool Payroll::addEmployee(Employee *e) {
	if (count < MAXIMUM) {
		employees[count] = e;
		count++;
		return true;
	}
	return false;
}

string Payroll::toString() const {
	stringstream output;
	
	for (uint i = 0; i < count; i++) {
		//output << employees[i]->toString() << "\n";
		
		switch(employees[i]->getType()) {
		case SALARIED 	: output << *((SalariedEmployee*) employees[i]) << "\n"; break;
		case HOURLY		: output << *((HourlyEmployee*) employees[i]) << "\n"; break;
		case COMMISSION	: output << *((CommissionEmployee*) employees[i]) << "\n"; break;
		}
	}
	return output.str();
}

float Payroll::calculatePayroll() const {
	float acum = 0;
	for (uint i = 0; i < count; i++) {
		acum += employees[i]->earnings();
	}
	return acum;
}

int Payroll::countSalariedEmployees() const {
	int acum = 0;
	for (uint i = 0; i < count; i++) {
		if (employees[i]->getType() == SALARIED) {
			acum++;
		}
	}
}

Employee* Payroll::lookUpEmployeeInfo(string id) const {
	for (uint i = 0; i < count; i++) {
		if (employees[i]->getId() == id) {
			return employees[i];
		}
	}
	return NULL;
}

Employee* Payroll::searchEmployeeWithMoreHours() const {
	HourlyEmployee* max = NULL;
	for (uint i = 0; i < count; i++) {
		if (employees[i]->getType() == HOURLY) {
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

bool Payroll::savePayroll(string filename) const {
	ofstream myFile;
	
	myFile.open(filename);
	if (myFile.is_open()) {
		myFile << count << "\n";
		for (uint i = 0; i < count; i++) {
			switch(employees[i]->getType()) {
				case SALARIED 	: myFile << *((SalariedEmployee*) employees[i]) << "\n"; break;
				case HOURLY		: myFile << *((HourlyEmployee*) employees[i]) << "\n"; break;
				case COMMISSION	: myFile << *((CommissionEmployee*) employees[i]) << "\n"; break;
			}
		}
		myFile.close();
		return true;
	}
	return false;
}

bool Payroll::loadPayroll(string filename) {
	string line;
	ifstream myFile;
	vector<string> tokens;
	
	myFile.open(filename);
	if (myFile.is_open()) {
		for (uint i = 0; i < count; i++) {
			delete employees[i];
		}
		
		getline(myFile, line);
		tokens = split(line, ',');
		count = stoi(tokens[0]);
		
		cout << "COUNT = " << count << "\n";
		
		for (uint i = 0; i < count; i++) {
			getline(myFile, line);
			cout << "LINE " << i << " - " << count << " = " << line << "\n";
			tokens = split(line, ',');
			switch(stoi(tokens[0])) {
				case SALARIED 	: employees[i] = new SalariedEmployee(tokens[1], tokens[2], stof(tokens[3])); break;
				case HOURLY		: employees[i] = new HourlyEmployee(tokens[1], tokens[2], stof(tokens[3]), stof(tokens[4])); break;
				case COMMISSION	: employees[i] = new HourlyEmployee(tokens[1], tokens[2], stof(tokens[3]), stof(tokens[4])); break;
			}
		}
		return true;
	}
	return false;
}
#endif