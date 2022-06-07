//2
#ifndef SELLING_H
#define SELLING_H

#include "order.h"

class SellingOrder : public Order {
public:
  SellingOrder(int, double, double);
  SellingOrder(const SellingOrder&);

  bool operator<(const Order*);
  bool operator<(const Order&);
};

SellingOrder::SellingOrder(int tId, double a, double p)
  : Order(tId, a, p, SELLING) {
}

SellingOrder::SellingOrder(const SellingOrder &other)
  : Order(other.traderId, other.amount, other.price, SELLING) {
}


bool SellingOrder::operator<(const Order *right) {
  /*
  if(price < obj->price)
			return -1;
		if(price > obj->price)
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
    return price < right->getPrice();
  }

  if (amount != right->getAmount()) {
    return amount > right->getAmount();
  }

  return (traderId < right->getTraderId());
}

bool SellingOrder::operator<(const Order &right) {
  if (type != right.getType()) {
    return (type < right.getType());
  }

  if (price != right.getPrice()) {
    return price < right.getPrice();
  }

  if (amount != right.getAmount()) {
    return amount > right.getAmount();
  }

  return (traderId < right.getTraderId());
}

#endif
