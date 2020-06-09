#include <iostream>
#include <sstream>
#include "employee.h"
#include "salaried.h"
#include "hourly.h"
#include "commission.h"
#include "payroll.h"

using namespace std;

Employee* captureData() {
	int type;
	Employee* result;
	
	do {
		cout << "Select the employee type\n";
		cout << "1. Salaried\n";
		cout << "2. Hourly\n";
		cout << "3. Commission\n";
		cin >> type;
		cin.ignore();
	} while (type != SALARIED && type != HOURLY && type != COMMISSION);
	switch(type) {
		case SALARIED	: result = new SalariedEmployee(); cin >> *((SalariedEmployee*) result); break;
		case HOURLY		: result = new HourlyEmployee(); cin >> *((HourlyEmployee*) result); break;
		case COMMISSION	: result = new CommissionEmployee(); cin >> *((CommissionEmployee*) result); break;
	}
	return result;
}

int main(int argc, char* argv[]) {
	Payroll payroll;
	Employee* result;
	string filename;
	int option;
	
	payroll.addEmployee(new SalariedEmployee("1", "Employee 1", 100));
	payroll.addEmployee(new HourlyEmployee("2", "Employee 2", 100, 30));
	payroll.addEmployee(new CommissionEmployee("3", "Employee 3", 30000, 0.15));
	payroll.addEmployee(new SalariedEmployee("4", "Employee 4", 100));
	payroll.addEmployee(new HourlyEmployee("5", "Employee 5", 100, 48));
	payroll.addEmployee(new CommissionEmployee("6", "Employee 6", 1000, 0.05));
	
	do {
		cout << "1. Add an employee\n";
		cout << "2. Display employees\n";
		cout << "3. Calculate payroll\n";
		cout << "4. Count salaried employee\n";
		cout << "5. Look up employee info\n";
		cout << "6. Search employee with more hours\n";
		cout << "7. Save to file\n";
		cout << "8. Load from file\n";
		cout << "9. Exit\n";
		cin >> option;
		cin.ignore();
		switch (option) {
			case 1 : result = captureData();
					 if (payroll.addEmployee(result)) {
						 cout << "Added to employee " << result->getName() << "\n";
					 } else {
						cout << "There was an error adding the employee\n";
					 }
					 break;
			case 2 : cout << "Payroll\n" << payroll.toString() << "\n"; break;
			case 3 : cout << "Total payroll: " << payroll.calculatePayroll() << "\n"; break;
			case 4 : cout << "Total salaried employee: " << payroll.countSalariedEmployees() << "\n"; break;
			case 5 : result = payroll.lookUpEmployeeInfo("1");
					 if (result != NULL) {
						cout << "Employee 1: " << result->toString() << "\n";
					 } else {
						cout << "Employee 1 not found\n"; 
					 }
					 break;
			case 6 : result = payroll.searchEmployeeWithMoreHours();
					 if (result != NULL) {
					 	cout << "Employee: " << result->toString() << "\n";
					 } else {
						cout << "Employee not found\n"; 
					 }
					 break;
			case 7 : cout << "Filename: ";
					 cin >> filename;
					 cin.ignore();
					 if (payroll.savePayroll(filename)) {
						cout << "The payroll was save to disk\n";
					 } else {
						cout << "There was an error saving the payroll\n";
					 }
					 break;
			case 8 : cout << "Filename: ";
					 cin >> filename;
					 cin.ignore();
					 if (payroll.loadPayroll(filename)) {
						cout << "The payroll was loaded from disk\n";
					 } else {
						cout << "There was an error loading the payroll\n";
					 }
					 break;
			case 9 : break;
			default: cout << "Wrong options\n"; break;
		}
		cout << "\n\n";
	} while (option != 9);
	return 0;
}