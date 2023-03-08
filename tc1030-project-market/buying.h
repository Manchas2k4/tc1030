// =========================================================
// File: buying.h
// Author:
// Date:
// Description:
// =========================================================
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

#endif
