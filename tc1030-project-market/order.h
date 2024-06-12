// 1
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

Order::Order(int tID, double a, double p, OrderType t) {
  traderId = tID;
  amount = a;
  price = p;
  type = t;
}

Order::Order(const Order &order) {
  traderId = order.traderId;
  amount = order.amount;
  price = order.price;
  type = order.type;
}

int Order::getTraderId() const {
  return traderId;
}

double Order::getAmount() const {
  return amount;
}

double Order::getPrice() const {
  return price;
}

OrderType Order::getType() const {
  return type;
}

double Order::getDollars() const {
  return amount * price;
}

std::string Order::toString() const {
  std::stringstream aux;

  aux << "TraderId " << traderId << ":"
      << std::fixed << std::setprecision(2) << amount << "$ "
      << std::fixed << std::setprecision(2) << price << "PQ";
  return aux.str();
}


bool Order::operator==(const Order *right) {
  return (type == right->type && traderId == right->traderId &&
          amount == right->amount && price == right->price);
}

bool Order::operator==(const Order &right) {
  return (type == right.type && traderId == right.traderId &&
          amount == right.amount && price == right.price);
}


#endif
