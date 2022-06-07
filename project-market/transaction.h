//3
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <cstdlib>
#include "order.h"
#include "selling.h"
#include "buying.h"

class Transaction {
private:
    SellingOrder *sellingOrder;
    BuyingOrder *buyingOrder;

public:
    Transaction(SellingOrder*, BuyingOrder*);
    Transaction(const Transaction&);
    ~Transaction();

    SellingOrder* getSellingOrder() const;
    BuyingOrder* getBuyingOrder() const;
};

Transaction::Transaction(SellingOrder *s, BuyingOrder *b)
  : sellingOrder(s), buyingOrder(b) {
}

Transaction::Transaction(const Transaction &other) {
  sellingOrder = new SellingOrder((*other.sellingOrder));
  buyingOrder = new BuyingOrder((*other.buyingOrder));
}

Transaction::~Transaction() {
  delete sellingOrder;
  delete buyingOrder;
  sellingOrder = NULL;
  buyingOrder = NULL;
}

SellingOrder* Transaction::getSellingOrder() const {
  return sellingOrder;
}

BuyingOrder* Transaction::getBuyingOrder() const {
  return buyingOrder;
}

#endif
