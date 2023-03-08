// =========================================================
// File: trader.h
// Author:
// Date:
// Description:
// =========================================================
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

#endif
