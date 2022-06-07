// =========================================================
// File: testing_selling.cpp
// Author: Dr. Pedro O. Perez-Murueta
// Date: 8/Apr/2022
// Description: This file contains the series of tests that
//							the SellingOrder class must pass.
// To compile: g++ -std=c++11 testing_light.cpp -o app
// To execute: ./app
// =========================================================
#define CATCH_CONFIG_MAIN
#include <string>
#include "catch.h"
#include "../selling.h"

TEST_CASE("testing basic constructor", "[SellingOrder(id, amount, price)]") {
	SellingOrder s1(1, 100, 10);

	REQUIRE(s1.getTraderId() == 1);
	REQUIRE(s1.getAmount() == 100);
	REQUIRE(s1.getPrice() == 10);
	REQUIRE(s1.getType() == SELLING);
	REQUIRE(s1.getDollars() == 1000);
}

TEST_CASE("testing copy constructor", "[SellingOrder(const SellingOrder&)]") {
	SellingOrder s1(1, 100, 10);
	SellingOrder s2(s1);

	REQUIRE(s2.getTraderId() == 1);
	REQUIRE(s2.getAmount() == 100);
	REQUIRE(s2.getPrice() == 10);
	REQUIRE(s2.getType() == SELLING);
	REQUIRE(s2.getDollars() == 1000);
}

TEST_CASE("testing operator==", "[operator==]") {
	SellingOrder s1(1, 100, 10);
	SellingOrder s2(s1);
	SellingOrder *s3 = new SellingOrder(1, 100, 10);
	SellingOrder s4(1, 101, 10);
	SellingOrder *s5 = new SellingOrder(1, 101, 10);
	bool result;

	result = (s1 == s2);
	REQUIRE(result == true);
	result = (s1 == s3);
	REQUIRE(result == true);
	result = (s1 == s4);
	REQUIRE(result == false);
	result = (s1 == s5);
	REQUIRE(result == false);

	delete s3;
	delete s5;
}

TEST_CASE("testing operator<", "[operator<]") {
	SellingOrder s1(1, 100, 10);
	SellingOrder s2(2, 100, 20);
	SellingOrder s3(3, 50, 10);
	SellingOrder s4(3, 100, 10);
	SellingOrder *s5 = new SellingOrder(2, 100, 20);
	SellingOrder *s6 = new SellingOrder(3, 50, 10);
	SellingOrder *s7 = new SellingOrder(3, 100, 10);
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
