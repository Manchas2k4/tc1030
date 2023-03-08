// =========================================================
// File: order.h
// Author:
// Date:
// Description:
// =========================================================
#ifndef ORDER_H
#define ORDER_H

#include <sstream>
#include <string>
#include <iomanip>

typedef enum {SELLING, BUYING} OrderType;

class Order {
protected:
  double amount, price;
  int traderId;
  OrderType type;

public:
  Order(int, double, double, OrderType);
  Order(const Order &);

  int getTraderId() const;
  double getAmount() const;
  double getPrice() const;
  OrderType getType() const;

  double getDollars() const;

  bool operator==(const Order*);
  bool operator==(const Order&);

  std::string toString() const;

  virtual bool operator<(const Order*) = 0;
  virtual bool operator<(const Order&) = 0;
};


#endif
