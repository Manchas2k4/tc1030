//5
#ifndef TRADER_H
#define TRADER_H

#include <sstream>
#include <string>
#include <iomanip>
#include "wallet.h"

class Trader {
private:
  int id;
  Wallet *wallet;

public:
  Trader(int, double, double);
  Trader(const Trader&);
  ~Trader();

  int getId() const;
  Wallet* getWallet() const;

  bool sell(double, double, int);
  bool buy(double, double, int);

  bool operator==(const Trader*);
  bool operator==(const Trader&);

  std::string toString() const;
};

Trader::Trader(int i, double dollars, double coins) {
  id = i;
  wallet = new Wallet(dollars, coins);
}

Trader::Trader(const Trader &other) {
  id = other.id;
  wallet = new Wallet(other.wallet->getDollars(), other.wallet->getCoins());
}

Trader::~Trader() {
  delete wallet;
  wallet = NULL;
}

int Trader::getId() const {
  return id;
}

Wallet* Trader::getWallet() const {
  return wallet;
}

bool Trader::sell(double amount, double price, int marketFee) {
  bool canIContinue = (wallet->checkBlockedCoins(amount) || id == 0);
  if (canIContinue) {
    wallet->payFromBlockedCoins(amount);
    wallet->depositDollars(amount * price * (1.0 - (marketFee / 100.0)));
  }
  return canIContinue;
}

bool Trader::buy(double amount, double price, int marketFee) {
  double dollars = amount * price;
  bool canIContinue = (wallet->checkBlockedDollars(dollars) || id == 0);
  if (canIContinue) {
    wallet->payFromBlockedDollars(dollars);
    wallet->depositCoins(amount);
  }
  return canIContinue;
}

bool Trader::operator==(const Trader *left) {
  return (id == left->getId());
}

bool Trader::operator==(const Trader &left) {
  return (id == left.getId());
}

std::string Trader::toString() const {
  std::stringstream aux;

  aux << "Trader " << id << ": " << wallet->toString();
  return aux.str();
}

#endif
