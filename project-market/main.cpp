#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "order.h"
#include "selling.h"
#include "buying.h"
#include "wallet.h"
#include "trader.h"
#include "market.h"

using namespace std;

int main(int argc, char* argv[]) {
  ifstream inputFile;
  ofstream outputFile;
  int A, B, C, D, query, traderId, invalidQueries;
  Market *market;
  vector<Trader*> traders;
  Wallet* wallet;
  double dollars, coins, price, amount;

  if (argc != 3) {
    cout << "usage: " << argv[0] << " input_file output_file\n";
    return -1;
  }

  inputFile.open(argv[1]);
  if (!inputFile.is_open()) {
    cout << argv[0] << ": File \"" << argv[1] << "\" not found\n";
    return -1;
  }

  outputFile.open(argv[2]);

  // SEED FEE USERS QUERIES
  inputFile >> A >> B >> C >> D;

  srand(A);

  market = new Market(B);
  traders.resize(C);
  invalidQueries = 0;

  for (int i = 0; i < C; i++) {
    inputFile >> dollars >> coins;
    traders[i] = new Trader(i, dollars, coins);
  }

  for (int i = 0; i < D; i++) {
    inputFile >> query;
    switch(query) {
      case 3:
        inputFile >> traderId >> dollars;
        traders[traderId]->getWallet()->depositDollars(dollars);
        break;
      case 4:
        inputFile >> traderId >> dollars;
        wallet = traders[traderId]->getWallet();
        if (wallet->checkWithDraw(dollars)) {
          wallet->withdrawDollars(dollars);
        } else {
          invalidQueries++;
        }
        break;
      case 5:
        inputFile >> traderId;
        outputFile << traders[traderId]->getWallet()->toString();
        break;
      case 10:
        inputFile >> traderId >> price >> amount;
        dollars = amount * price;
        wallet = traders[traderId]->getWallet();
        if (traderId == 0) {
          market->addBuyingOrder(new BuyingOrder(traderId, amount, price));
        } else if (wallet->checkWithDraw(dollars)) {
          market->addBuyingOrder(new BuyingOrder(traderId, amount, price));
          wallet->blockDollars(dollars);
        } else {
          invalidQueries++;
        }
        break;
      case 11:
        inputFile >> traderId >> amount;
        price = market->topSellingPrice();
        dollars = amount * price;
        wallet = traders[traderId]->getWallet();
        if (market->getSellingOrders().empty()) {
          invalidQueries++;
        } else if (traderId == 0) {
          market->addBuyingOrder(new BuyingOrder(traderId, amount, price));
        } else if (wallet->checkWithDraw(dollars)) {
          market->addBuyingOrder(new BuyingOrder(traderId, amount, price));
          wallet->blockDollars(dollars);
        } else {
          invalidQueries++;
        }
        break;
      case 20:
        inputFile >> traderId >> price >> amount;
        wallet = traders[traderId]->getWallet();
        if (traderId == 0) {
          market->addSellingOrder(new SellingOrder(traderId, amount, price));
        } else if (wallet->checkSelling(amount)) {
          market->addSellingOrder(new SellingOrder(traderId, amount, price));
          wallet->blockCoins(amount);
        } else {
          invalidQueries++;
        }
        break;
      case 21:
        inputFile >> traderId >> amount;
        price = market->topBuyingPrice();
        wallet = traders[traderId]->getWallet();
        if (market->getBuyingOrders().empty()) {
          invalidQueries++;
        } else if (traderId == 0) {
          market->addSellingOrder(new SellingOrder(traderId, amount, price));
        } else if (wallet->checkWithDraw(dollars)) {
          market->addSellingOrder(new SellingOrder(traderId, amount, price));
          wallet->blockCoins(amount);
        } else {
          invalidQueries++;
        }
        break;
      case 500:
        outputFile << market->marketInfo() << "\n";
        break;
      case 501:
        outputFile << market->transactionInfo() << "\n";
        break;
      case 502:
        outputFile << "Number of invalid queries: " << invalidQueries << "\n";
        break;
      case 505:
        outputFile << market->currentPriceInfo() << "\n";
        break;
      case 555:
        for (Trader *trader : traders) {
          outputFile << trader->toString() << "\n";
        }
        break;
      case 666:
        inputFile >> price;
        market->makeOpenMarketOperation(price, traders);
        break;
      case 777:
        for (Trader *trader : traders) {
          trader->getWallet()->depositCoins(((double) rand() / (double) RAND_MAX) * 100.0);
        }
        break;
      default:
        outputFile << "Invalid query number: " << query << "\n";
        break;
    }
    market->checkTransactions(traders);
  }

  inputFile.close();
  outputFile.close();
  return 0;
}
