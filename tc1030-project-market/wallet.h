// =========================================================
// File: wallet.h
// Author:
// Date:
// Description:
// =========================================================
#ifndef WALLET_H
#define WALLET_H

#include <sstream>
#include <string>
#include <iomanip>

class Wallet {
private:
  double dollars, coins, blockedDollars, blockedCoins;

public:
  Wallet(double, double);
  Wallet(const Wallet&);

  double getDollars() const;
  double getCoins() const;
  double getBlockedDollars() const;
  double getBlockedCoins() const;

  void depositDollars(double);
  void depositCoins(double);

  void withdrawDollars(double);

  void blockDollars(double);
  void blockCoins(double);

  void returnDollars(double);

  void payFromBlockedDollars(double);
  void payFromBlockedCoins(double);
  bool checkWithDraw(double);
  bool checkSelling(double);
  bool checkBlockedDollars(double);
  bool checkBlockedCoins(double);

  std::string toString() const;
};


#endif
