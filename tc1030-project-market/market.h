// =========================================================
// File: market.h
// Author:
// Date:
// Description:
// =========================================================
#ifndef MARKET_H
#define MARKET_H

#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <list>
#include <queue>
#include "order.h"
#include "selling.h"
#include "buying.h"
#include "wallet.h"
#include "trader.h"
#include "transaction.h"

class Market {
private:
  std::priority_queue<Order*> sellingOrders;
  std::priority_queue<Order*> buyingOrders;
  std::list<Transaction*> transactions;
  int fee, noOfSuccessfulTransactions;

public:
  Market(int);

  int getFee() const;
  std::priority_queue<Order*> getSellingOrders() const;
  std::priority_queue<Order*> getBuyingOrders() const;
  int getNoOfSuccessfulTransactions() const;

  void addSellingOrder(SellingOrder*);
  void addBuyingOrder(BuyingOrder*);

  double topBuyingPrice() const;
  double topSellingPrice() const;

  void makeOpenMarketOperation(double, std::vector<Trader*>&);
  void checkTransactions(std::vector<Trader*>&);

  std::string marketInfo() const;
  std::string currentPriceInfo() const;
  std::string transactionInfo() const;
};

#endif
