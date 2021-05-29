/*************************************************************
* File: twoday.h
* Author: Pedro Perez
* Description: This file contains the definition of
*              TwoDayPackage class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#ifndef TWODAY_H
#define TWODAY_H

#include "package.h"

class TwoDayPackage : public Package {
private:
	double flatFee;

public:
	TwoDayPackage();
	TwoDayPackage(std::string, std::string, double, double, double);
	TwoDayPackage(const TwoDayPackage&);

	double getFlatFee() const;

	void setFlatFee(double);

	double calculateCost() const;
};

#endif