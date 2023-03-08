// =========================================================
// File: testing_port2.cpp
// Author: Dr. Pedro O. Perez-Murueta
// Date: 4/Jan/2022
// Description: This file contains the series of tests that
//							the Port class must pass.
// IMPORTANT: This file must be used AFTER the
// testing of Ship class.
// To compile: g++ -std=c++11 testing_transaction.cpp -o app
// To execute: ./app
// =========================================================
#define CATCH_CONFIG_MAIN
#include <string>
#include "catch.h"
#include "../transaction.h"

TEST_CASE("testing basic constructor", "[Transaction(Selling*, Buying*)]") {
	SellingOrder *s1 = new SellingOrder(1, 100, 10);
	BuyingOrder *b1 = new BuyingOrder(3, 50, 100);
	Transaction t1(s1, b1);

	REQUIRE(t1.getSellingOrder() == s1);
	REQUIRE(t1.getBuyingOrder() == b1);
}

TEST_CASE("testing copy constructor", "[Transaction(const Transaction&)]") {
	SellingOrder *s1 = new SellingOrder(1, 100, 10);
	BuyingOrder *b1 = new BuyingOrder(3, 50, 100);
	Transaction t1(s1, b1);
	Transaction t2(t1);

	REQUIRE(t2.getSellingOrder() != s1);
	REQUIRE(t2.getBuyingOrder() != b1);
}
