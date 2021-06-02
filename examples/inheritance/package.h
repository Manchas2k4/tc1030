/*************************************************************
* File: package.h
* Author: Pedro Perez
* Description: This file contains the definition of
*              Package class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
#include <string>

class Package {
protected:
	std::string sender;
	std::string recipient;
	double weight;
	double costPerOunce;

public:
	Package();
	Package(std::string, std::string, double, double);
	Package(const Package&);

	std::string getSender() const;
	std::string getRecipient() const;
	double getWeight() const;
	double getCostPerOunce() const;

	void setSender(std::string);
	void setRecipient(std::string);
	void setWeight(double);
	void setCostPerOunce(double);

	double calculateCost() const;
};

#endif
