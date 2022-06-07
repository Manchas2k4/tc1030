//4
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

Wallet::Wallet(double d, double c) {
  dollars = d;
  coins = c;
  blockedDollars = 0;
  blockedCoins = 0;
}

Wallet::Wallet(const Wallet &other)
  : dollars(other.dollars), coins(other.coins),
    blockedDollars(other.blockedDollars), blockedCoins(other.blockedCoins) {
}

double Wallet::getDollars() const {
  return dollars;
}
double Wallet::getCoins() const {
  return coins;
}

double Wallet::getBlockedDollars() const {
  return blockedDollars;
}

double Wallet::getBlockedCoins() const {
  return blockedCoins;
}

void Wallet::depositDollars(double d) {
  if (d < 0) {
    return;
  }

  dollars += d;
}

void Wallet::depositCoins(double c) {
  if (c < 0) {
    return;
  }

  coins += c;
}

void Wallet::withdrawDollars(double d) {
  if (d < 0) {
    return;
  }

  if (d > dollars) {
    return;
  }

  dollars -= d;
}

void Wallet::blockDollars(double d) {
  if (d < 0) {
    return;
  }

  if (d > dollars) {
    return;
  }

  dollars -= d;
  blockedDollars += d;
}

void Wallet::blockCoins(double c) {
  if (c < 0) {
    return;
  }

  if (c > coins) {
    return;
  }

  coins -= c;
  blockedCoins += c;
}

void Wallet::returnDollars(double d) {
  if (d < 0) {
    return;
  }

  if (d > blockedDollars) {
    return;
  }

  dollars += d;
  blockedDollars -= d;
}

void Wallet::payFromBlockedDollars(double d) {
  if (d < 0) {
    return;
  }

  if (d > blockedDollars) {
    return;
  }

  blockedDollars -= d;
}

void Wallet::payFromBlockedCoins(double c) {
  if (c < 0) {
    return;
  }

  if (c > blockedCoins) {
    return;
  }

  blockedCoins -= c;
}

bool Wallet::checkWithDraw(double d) {
  return ((d >= 0) && (d <= dollars));
}

bool Wallet::checkSelling(double c) {
  return ((c >= 0) && (c <= coins));
}

bool Wallet::checkBlockedDollars(double d) {
  return ((d >= 0) && (d <= blockedDollars));
}

bool Wallet::checkBlockedCoins(double c) {
  return ((c >= 0) && (c <= blockedCoins));
}

std::string Wallet::toString() const {
  std::stringstream aux;

  aux << std::fixed << std::setprecision(2) << (dollars + blockedDollars) << "$ "
      << std::fixed << std::setprecision(2) << (coins + blockedCoins) << "PQ";
  return aux.str();
}

#endif
