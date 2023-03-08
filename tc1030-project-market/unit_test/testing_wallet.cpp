// =========================================================
// File: testing_wallet.cpp
// Author: Dr. Pedro O. Perez-Murueta
// Date: 8/Apr/2022
// Description: This file contains the series of tests that
//							the Wallet class must pass.
// To compile: g++ -std=c++11 testing_wallet.cpp -o app
// To execute: ./app
// =========================================================
#define CATCH_CONFIG_MAIN
#include <string>
#include "catch.h"
#include "../wallet.h"

TEST_CASE("testing basic constructor", "[Wallet(dollar, coins)]") {
	Wallet w1(100, 10);

	REQUIRE(w1.getDollars() == 100);
	REQUIRE(w1.getCoins() == 10);
  REQUIRE(w1.getBlockedDollars() == 0);
	REQUIRE(w1.getBlockedCoins() == 0);
}

TEST_CASE("testing copy constructor", "[Wallet(const Wallet&)]") {
	Wallet w1(100, 10);
	Wallet w2(w1);

	REQUIRE(w2.getDollars() == 100);
	REQUIRE(w2.getCoins() == 10);
  REQUIRE(w2.getBlockedDollars() == 0);
	REQUIRE(w2.getBlockedCoins() == 0);
}

TEST_CASE("testing depositDollars", "[depositDollars(amount)]") {
	Wallet w1(100, 10);

	w1.depositDollars(-10);
	REQUIRE(w1.getDollars() == 100);
	w1.depositDollars(10);
	REQUIRE(w1.getDollars() == 110);
}

TEST_CASE("testing depositCoins", "[depositCoins(amount)]") {
	Wallet w1(100, 10);

	w1.depositCoins(-10);
	REQUIRE(w1.getCoins() == 10);
	w1.depositCoins(10);
	REQUIRE(w1.getCoins() == 20);
}

TEST_CASE("testing withdrawDollars", "[withdrawDollars(amount)]") {
	Wallet w1(100, 10);

	w1.withdrawDollars(-10);
	REQUIRE(w1.getDollars() == 100);
	w1.withdrawDollars(10);
	REQUIRE(w1.getDollars() == 90);
}

TEST_CASE("testing blockDollars", "[blockDollars(amount)]") {
	Wallet w1(100, 10);

	w1.blockDollars(-10);
	REQUIRE(w1.getDollars() == 100);
	REQUIRE(w1.getBlockedDollars() == 0);
	w1.blockDollars(200);
	REQUIRE(w1.getDollars() == 100);
	REQUIRE(w1.getBlockedDollars() == 0);
	w1.blockDollars(50);
	REQUIRE(w1.getDollars() == 50);
	REQUIRE(w1.getBlockedDollars() == 50);
}

TEST_CASE("testing blockCoins", "[blockCoins(amount)]") {
	Wallet w1(100, 10);

	w1.blockCoins(-10);
	REQUIRE(w1.getCoins() == 10);
	REQUIRE(w1.getBlockedCoins() == 0);
	w1.blockCoins(20);
	REQUIRE(w1.getCoins() == 10);
	REQUIRE(w1.getBlockedCoins() == 0);
	w1.blockCoins(5);
	REQUIRE(w1.getCoins() == 5);
	REQUIRE(w1.getBlockedCoins() == 5);
}

TEST_CASE("testing returnDollars", "[returnDollars(amount)]") {
	Wallet w1(100, 10);

	w1.blockDollars(50);
	w1.returnDollars(-30);
	REQUIRE(w1.getDollars() == 50);
	REQUIRE(w1.getBlockedDollars() == 50);
	w1.returnDollars(100);
	REQUIRE(w1.getDollars() == 50);
	REQUIRE(w1.getBlockedDollars() == 50);
	w1.returnDollars(30);
	REQUIRE(w1.getDollars() == 80);
	REQUIRE(w1.getBlockedDollars() == 20);
}

TEST_CASE("testing payFromBlockedDollars", "[payFromBlockedDollars(amount)]") {
	Wallet w1(100, 10);

	w1.blockDollars(50);
	w1.payFromBlockedDollars(-30);
	REQUIRE(w1.getBlockedDollars() == 50);
	w1.payFromBlockedDollars(100);
	REQUIRE(w1.getBlockedDollars() == 50);
	w1.payFromBlockedDollars(30);
	REQUIRE(w1.getBlockedDollars() == 20);
}

TEST_CASE("testing payFromBlockedCoins", "[payFromBlockedCoins(amount)]") {
	Wallet w1(100, 10);

	w1.blockCoins(5);
	w1.payFromBlockedCoins(-30);
	REQUIRE(w1.getBlockedCoins() == 5);
	w1.payFromBlockedCoins(100);
	REQUIRE(w1.getBlockedCoins() == 5);
	w1.payFromBlockedCoins(3);
	REQUIRE(w1.getBlockedCoins() == 2);
}

TEST_CASE("testing checkXY", "[checkXY(amount)]") {
	Wallet w1(100, 10);

	w1.blockDollars(50);
	w1.blockCoins(5);
	REQUIRE(w1.checkWithDraw(-10) == false);
	REQUIRE(w1.checkWithDraw(10) == true);
	REQUIRE(w1.checkWithDraw(100) == false);

	REQUIRE(w1.checkSelling(-1) == false);
	REQUIRE(w1.checkSelling(1) == true);
	REQUIRE(w1.checkSelling(10) == false);

	REQUIRE(w1.checkBlockedDollars(-10) == false);
	REQUIRE(w1.checkBlockedDollars(10) == true);
	REQUIRE(w1.checkBlockedDollars(100) == false);

	REQUIRE(w1.checkBlockedCoins(-1) == false);
	REQUIRE(w1.checkBlockedCoins(1) == true);
	REQUIRE(w1.checkBlockedCoins(10) == false);
}
