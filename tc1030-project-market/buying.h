//3
#ifndef BUYING_H
#define BUYING_H

#include "order.h"

class BuyingOrder : public Order {
public:
  BuyingOrder(int, double, double);
  BuyingOrder(const BuyingOrder &);

  bool operator<(const Order*);
  bool operator<(const Order&);
};

BuyingOrder::BuyingOrder(int tId, double a, double p)
  : Order(tId, a, p, BUYING) {
}

BuyingOrder::BuyingOrder(const BuyingOrder &other)
  : Order(other.traderId, other.amount, other.price, other.type) {
}

bool BuyingOrder::operator<(const Order *right) {
  /*
  if(price > e.price)
			return -1;
		if(price < obj->price)
			return 1;
		if(amount > obj->amount)
			return -1;
		if(amount < obj->amount)
			return 1;
		if(traderID < obj->traderID)
			return -1;
		if(traderID > obj->traderID)
			return 1;
		return 0;
  */
  if (type != right->getType()) {
    return (type < right->getType());
  }

  if (price != right->getPrice()) {
    return price > right->getPrice();
  }

  if (amount != right->getAmount()) {
    return amount > right->getAmount();
  }

  return (traderId < right->getTraderId());
}

bool BuyingOrder::operator<(const Order &right) {
  if (type != right.getType()) {
    return (type < right.getType());
  }

  if (price != right.getPrice()) {
    return price > right.getPrice();
  }

  if (amount != right.getAmount()) {
    return amount > right.getAmount();
  }

  return (traderId < right.getTraderId());
}

#endif
