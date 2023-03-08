// =========================================================
// File: selling.h
// Author:
// Date:
// Description:
// =========================================================
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

#endif
