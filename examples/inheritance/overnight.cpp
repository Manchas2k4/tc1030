/*************************************************************
* File: overnight.cpp
* Author: Pedro Perez
* Description: This file contains the implementation of
*              OvernightPackage class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#include "overnight.h"

OvernightPackage::OvernightPackage() 
	: Package(), aditionalFee(0.0) {
}

OvernightPackage::OvernightPackage(std::string s, std::string r, 
	double w, double c, double a)
	: Package(s, r, w, c) {
	aditionalFee = (a < 0)? -a : a;
}

OvernightPackage::OvernightPackage(const OvernightPackage &p)
	: Package(p.sender, p.recipient, p.weight, p.costPerOunce), 
	  aditionalFee(p.aditionalFee) {
}

double OvernightPackage::getAditionalFee() const {
	return aditionalFee;
}

void OvernightPackage::setAditionalFee(double a) {
	aditionalFee = (a < 0)? -a : a;
}

double OvernightPackage::calculateCost() const {
	return weight * (costPerOunce + aditionalFee);
}