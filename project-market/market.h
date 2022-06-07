//6
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

Market::Market(int f) {
  fee = f;
  noOfSuccessfulTransactions = 0;
}

int Market::getFee() const {
  return fee;
}

int Market::getNoOfSuccessfulTransactions() const {
  return noOfSuccessfulTransactions;
}

std::priority_queue<Order*> Market::getSellingOrders() const {
  return sellingOrders;
}

std::priority_queue<Order*> Market::getBuyingOrders() const {
  return buyingOrders;
}

void Market::addSellingOrder(SellingOrder *s) {
  sellingOrders.push(s);
}

void Market::addBuyingOrder(BuyingOrder *b) {
  buyingOrders.push(b);
}

double Market::topBuyingPrice() const {
  return (buyingOrders.empty()? 0.0 : buyingOrders.top()->getPrice());
}

double Market::topSellingPrice() const {
  return (sellingOrders.empty()? 0.0 : sellingOrders.top()->getPrice());
}

void Market::makeOpenMarketOperation(double price, std::vector<Trader*> &traders) {
  while (!buyingOrders.empty() && topBuyingPrice() >= price) {
    BuyingOrder *bOrder = (BuyingOrder *) buyingOrders.top();
    addSellingOrder(new SellingOrder(0, bOrder->getAmount(), bOrder->getPrice()));
    checkTransactions(traders);
  }

  while (!sellingOrders.empty() && topSellingPrice() <= price) {
    SellingOrder *sOrder = (SellingOrder *) sellingOrders.top();
    addBuyingOrder(new BuyingOrder(0, sOrder->getAmount(), sOrder->getPrice()));
    checkTransactions(traders);
  }
}

void Market::checkTransactions(std::vector<Trader*> &traders) {
  double tradedAmount = 0;
  bool sellFlag, buyFlag;

  while(!buyingOrders.empty() && !sellingOrders.empty() && topBuyingPrice() >= topSellingPrice()) {
    SellingOrder *sOrder = (SellingOrder *) sellingOrders.top(); sellingOrders.pop();
    BuyingOrder *bOrder = (BuyingOrder *) buyingOrders.top(); buyingOrders.pop();

    if (sOrder->getAmount() > bOrder->getAmount()) {
      tradedAmount = bOrder->getAmount();
      addSellingOrder(new SellingOrder(sOrder->getTraderId(), sOrder->getPrice(), sOrder->getAmount() - tradedAmount));
    } else if (sOrder->getAmount() < bOrder->getAmount()) {
      tradedAmount = sOrder->getAmount();
      addBuyingOrder(new BuyingOrder(bOrder->getTraderId(), bOrder->getPrice(), bOrder->getAmount() - tradedAmount));
    } else {
      tradedAmount = bOrder->getAmount();
    }

    sellFlag = traders[sOrder->getTraderId()]->sell(tradedAmount, sOrder->getPrice(), getFee());
    buyFlag = traders[bOrder->getTraderId()]->buy(tradedAmount, sOrder->getPrice(), getFee());

    if (sellFlag && buyFlag) {
      noOfSuccessfulTransactions++;
    }

    if (bOrder->getPrice() > sOrder->getPrice()) {
      traders[bOrder->getTraderId()]->getWallet()->returnDollars((bOrder->getPrice() - sOrder->getPrice()) * tradedAmount);
    }

    transactions.push_back(new Transaction(sOrder, bOrder));
  }
}

std::string Market::marketInfo() const {
  std::stringstream aux;
  double dollarsSum, coinsSum;
  std::priority_queue<Order*> bOrders(buyingOrders);
  std::priority_queue<Order*> sOrders(sellingOrders);
  BuyingOrder *bOrder;
  SellingOrder *sOrder;

  dollarsSum = 0;
  while(!bOrders.empty()) {
    bOrder = (BuyingOrder *) bOrders.top(); bOrders.pop();
    dollarsSum += bOrder->getDollars();
  }

  coinsSum = 0;
  while(!sOrders.empty()) {
    sOrder = (SellingOrder *) sOrders.top(); sOrders.pop();
    coinsSum += sOrder->getAmount();
  }

  aux << "Current market size: " << std::fixed << std::setprecision(5)
      << dollarsSum << " " << coinsSum;
  return aux.str();
}

std::string Market::currentPriceInfo() const {
  std::stringstream aux;
  double buyingOrderPrice, sellingOrderPrice, averagePrice;
  bool buyFlag, sellFlag;

  buyingOrderPrice = topBuyingPrice();
  sellingOrderPrice = topSellingPrice();
  buyFlag = buyingOrders.empty();
  sellFlag = sellingOrders.empty();

  averagePrice = 0;
  if (buyFlag && sellFlag) {
    averagePrice = 0;
  } else if (!buyFlag && sellFlag) {
    averagePrice = buyingOrderPrice;
  } else if (buyFlag && !sellFlag) {
    averagePrice = sellingOrderPrice;
  } else {
    averagePrice = (buyingOrderPrice + sellingOrderPrice) / 2.0;
  }

  aux << "Current prices: " << std::fixed << std::setprecision(5)
      << buyingOrderPrice << " " << sellingOrderPrice << " "
      << averagePrice;
  return aux.str();
}

std::string Market::transactionInfo() const {
  std::stringstream aux;

  aux << "Number of successful transactions: " << noOfSuccessfulTransactions;
  return aux.str();
}
#endif
