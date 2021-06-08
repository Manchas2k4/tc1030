#ifndef CURRENCY_H
#define CURRENCY_H

typedef enum {NONE, PESOS, DOLLARS} CurrencyType;

class Currency {
protected:
	double value;
	CurrencyType type;

public:
	Currency();
	Currency(double);
	Currency(CurrencyType, double);

	CurrencyType getType() const;

	virtual double getMXN() const = 0;
	virtual double getUSD() const = 0;
};

class Peso : public Currency {
public:
	Peso(double); 

	double getMXN() const;
	double getUSD() const;
};

class Dollar : public Currency {
public:
	Dollar(double); 

	double getMXN() const;
	double getUSD() const;
};

#endif