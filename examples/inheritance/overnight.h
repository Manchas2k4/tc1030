/*************************************************************
* File: overnight.h
* Author: Pedro Perez
* Description: This file contains the definition of
*              OvernightPackage class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#ifndef OVERNIGHT_H
#define OVERNIGHT_H

#include "package.h"

class OvernightPackage : public Package {
private:
	double aditionalFee;

public:
	OvernightPackage();
	OvernightPackage(std::string, std::string, double, double, double);
	OvernightPackage(const OvernightPackage&);

	double getAditionalFee() const;

	void setAditionalFee(double);

	double calculateCost() const;
};

#endif