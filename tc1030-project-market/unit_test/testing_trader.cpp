// =========================================================
// File: testing_trader.cpp
// Author: Dr. Pedro O. Perez-Murueta
// Date: 8/Apr/2022
// Description: This file contains the series of tests that
//							the Trader class must pass.
// To compile: g++ -std=c++11 testing_trader.cpp -o app
// To execute: ./app
// =========================================================
#define CATCH_CONFIG_MAIN
#include <string>
#include "catch.h"
#include "../trader.h"

TEST_CASE("testing basic constructor", "[Trader(id, dollars, coins)]") {
	Trader t1(1, 100, 10);
	Wallet *w1;

	REQUIRE(t1.getId() == 1);
	w1 = t1.getWallet();
	REQUIRE(w1 != NULL);
	REQUIRE(w1->getDollars() == 100);
	REQUIRE(w1->getCoins() == 10);
  REQUIRE(w1->getBlockedDollars() == 0);
	REQUIRE(w1->getBlockedCoins() == 0);
}

TEST_CASE("testing copy constructor", "[Trader(const Trader&)]") {
	Trader t1(1, 100, 10);
	Trader t2(t1);
	Wallet *w2;

	REQUIRE(t2.getId() == 1);
	w2 = t2.getWallet();
	REQUIRE(w2 != NULL);
	REQUIRE(w2->getDollars() == 100);
	REQUIRE(w2->getCoins() == 10);
  REQUIRE(w2->getBlockedDollars() == 0);
	REQUIRE(w2->getBlockedCoins() == 0);
}

TEST_CASE("testing sell", "[sell(amount, price, marketFee)]") {
	Trader t1(1, 100, 100);
	Wallet *w1;

	w1 = t1.getWallet();
	w1->blockCoins(50);
	REQUIRE(t1.sell(100, 100, 10) == false);
	REQUIRE(w1->getBlockedCoins() == 50);
	REQUIRE(w1->getDollars() == 100);

	REQUIRE(t1.sell(50, 100, 10) == true);
	REQUIRE(w1->getBlockedCoins() == 0);
	REQUIRE(w1->getDollars() == 4600);
}

TEST_CASE("testing buy", "[buy(amount, price, marketFee)]") {
	Trader t1(1, 1000, 100);
	Wallet *w1;

	w1 = t1.getWallet();
	w1->blockDollars(500);
	REQUIRE(t1.buy(100, 100, 10) == false);
	REQUIRE(w1->getBlockedDollars() == 500);
	REQUIRE(w1->getCoins() == 100);

	REQUIRE(t1.buy(50, 10, 10) == true);
	REQUIRE(w1->getBlockedDollars() == 0);
	REQUIRE(w1->getCoins() == 150);
}

TEST_CASE("testing operator==", "[operator==(const Trader*)]") {
	Trader t1(1, 1000, 100);
	Trader t2(1, 1000, 100);
	Trader t3(2, 1000, 100);
	Trader *t4 = new Trader(1, 1000, 100);
	Trader *t5 = new Trader(2, 1000, 100);
	bool result;

	result = (t1 == t2);
	REQUIRE(result == true);
	result = (t1 == t3);
	REQUIRE(result == false);
	result = (t1 == t4);
	REQUIRE(result == true);
	result = (t1 == t5);
	REQUIRE(result == false);

	delete t4;
	delete t5;
}
