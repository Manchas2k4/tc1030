// =========================================================
// File: transaction.h
// Author:
// Date:
// Description:
// =========================================================
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

#endif
