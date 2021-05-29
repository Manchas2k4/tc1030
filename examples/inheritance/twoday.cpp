/*************************************************************
* File: twoday.cpp
* Author: Pedro Perez
* Description: This file contains the implementation of
*              TwoDayPackage class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#include "twoday.h"

TwoDayPackage::TwoDayPackage()
	: Package(), flatFee(0.0) {
}

TwoDayPackage::TwoDayPackage(std::string s, std::string r, double w, double c, double f)
	: Package(s, r, w, c) {
	flatFee = (f < 0)? -f : f;
}

TwoDayPackage::TwoDayPackage(const TwoDayPackage &p)
	: Package(p.sender, p.recipient, p.weight, p.costPerOunce), 
	  flatFee(p.flatFee) {
}

double TwoDayPackage::getFlatFee() const {
	return flatFee;
}

void TwoDayPackage::setFlatFee(double f) {
	flatFee = (f < 0)? -f : f;
}

double TwoDayPackage::calculateCost() const {
	// return flatFee + (weight * costPerOunce);
	return Package::calculateCost() + flatFee;
}