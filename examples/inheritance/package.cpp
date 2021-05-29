/*************************************************************
* File: package.cpp
* Author: Pedro Perez
* Description: This file contains the implementation of
*              Package class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#include "package.h"

Package::Package() 
	: sender("none"), recipient("none"), weight(0.0), costPerOunce(0.0) {
}

Package::Package(std::string s, std::string r, double w, double c) 
		: sender(s), recipient(r) {
	weight = (w < 0)? -w : w;
	costPerOunce = (c < 0)? -c : c;
}

Package::Package(const Package &p)
		: sender(p.sender), recipient(p.recipient), weight(p.weight), 
			costPerOunce(p.costPerOunce) {
}

std::string Package::getSender() const {
	return sender;
}

std::string Package::getRecipient() const {
	return recipient;
}

double Package::getWeight() const {
	return weight;
}

double Package::getCostPerOunce() const {
	return costPerOunce;
}

void Package::setSender(std::string s) {
	sender = s;
}

void Package::setRecipient(std::string r) {
	recipient = r;
}

void Package::setWeight(double w) {
	weight = (w < 0)? -w : w;
}

void Package::setCostPerOunce(double c) {
	costPerOunce = (c < 0)? -c : c;
}

double Package::calculateCost() const {
	return costPerOunce * weight;
}