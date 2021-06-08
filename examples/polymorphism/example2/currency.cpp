#include "currency.h"

Currency::Currency() 
	: type(NONE), value(0.0) {
}

Currency::Currency(double v) 
	: type(NONE), value(v) {
}

Currency::Currency(CurrencyType t, double v) 
	: type(t), value(v) {
}

CurrencyType Currency::getType() const {
	return type;
}

Peso::Peso(double v)
	: Currency(PESOS, v) {
}

double Peso::getMXN() const {
	return value;
}

double Peso::getUSD() const {
	return value / 20.0;
}

Dollar::Dollar(double v)
	: Currency(DOLLARS, v) {
}

double Dollar::getMXN() const {
	return value * 20.0;
}

double Dollar::getUSD() const {
	return value;
}
