// =========================================================
// File: testing_buying.cpp
// Author: Dr. Pedro O. Perez-Murueta
// Date: 8/Apr/2022
// Description: This file contains the series of tests that
//							the HeavyContainer class must pass.
// To compile: g++ -std=c++11 testing_buying.cpp -o app
// To execute: ./app
// =========================================================
#define CATCH_CONFIG_MAIN
#include <string>
#include "catch.h"
#include "../buying.h"

TEST_CASE("testing basic constructor", "[BuyingOrder(id, amount, price)]") {
	BuyingOrder s1(1, 100, 10);

	REQUIRE(s1.getTraderId() == 1);
	REQUIRE(s1.getAmount() == 100);
	REQUIRE(s1.getPrice() == 10);
	REQUIRE(s1.getType() == BUYING);
	REQUIRE(s1.getDollars() == 1000);
}

TEST_CASE("testing copy constructor", "[BuyingOrder(const BuyingOrder&)]") {
	BuyingOrder s1(1, 100, 10);
	BuyingOrder s2(s1);

	REQUIRE(s2.getTraderId() == 1);
	REQUIRE(s2.getAmount() == 100);
	REQUIRE(s2.getPrice() == 10);
	REQUIRE(s2.getType() == BUYING);
	REQUIRE(s2.getDollars() == 1000);
}

TEST_CASE("testing operator<", "[operator<]") {
	BuyingOrder s1(1, 100, 100);
	BuyingOrder s2(2, 100, 20);
	BuyingOrder s3(3, 50, 100);
	BuyingOrder s4(3, 100, 10);
	BuyingOrder *s5 = new BuyingOrder(2, 100, 20);
	BuyingOrder *s6 = new BuyingOrder(3, 50, 100);
	BuyingOrder *s7 = new BuyingOrder(3, 100, 10);
	bool result;

	result = (s1 < s2);
	REQUIRE(result == true);
	result = (s1 < s3);
	REQUIRE(result == true);
	result = (s1 < s4);
	REQUIRE(result == true);


	result = (s2 < s1);
	REQUIRE(result == false);
	result = (s3 < s1);
	REQUIRE(result == false);
	result = (s4 < s1);
	REQUIRE(result == false);

	result = (s1 < s5);
	REQUIRE(result == true);
	result = (s1 < s6);
	REQUIRE(result == true);
	result = (s1 < s7);
	REQUIRE(result == true);

	delete s5;
	delete s6;
	delete s7;
}
