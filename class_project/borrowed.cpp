/*************************************************************
* File: borrowed.cpp
* Author: Pedro Perez
* Description: This file contains the implementation of
*              BorrowedItem class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#include "borrowed.h"

BorrowedItem::BorrowedItem()
  : userId(0), itemId(0), maximumDays(0) {
}

BorrowedItem::BorrowedItem(uint ui, uint ii, const Date &d, uint m)
  : userId(ui), itemId(ii), startDate(d), maximumDays(0) {
}

BorrowedItem::BorrowedItem(const BorrowedItem &b)
  : userId(b.userId), itemId(b.itemId),
    startDate(b.startDate), maximumDays(b.maximumDays) {
}

BorrowedItem::BorrowedItem(std::string line) {
  std::vector<std::string> result;

  result = split(line);
  userId = (uint) stol(result[0]);
  itemId = (uint) stol(result[1]);
  startDate = Date(result[2]);
  maximumDays = (uint) stol(result[3]);
}

uint BorrowedItem::getUserId() const {
    return userId;
}

uint BorrowedItem::getItemId() const {
  return itemId;
}

Date BorrowedItem::getStartDate() const {
  return startDate;
}

uint BorrowedItem::getMaximumDays() const {
  return maximumDays;
}

void BorrowedItem::setUserId(uint i) {
  userId = i;
}

void BorrowedItem::setItemId(uint i) {
  itemId = i;
}

void BorrowedItem::setStartDate(const Date &d) {
  startDate = d;
}

void BorrowedItem::setMaximumDays(uint m) {
  maximumDays = m;
}

std::string BorrowedItem::toString() const {
  std::stringstream aux;

	aux << userId << "," << itemId << startDate.toString() << "," << maximumDays;
	return aux.str();
}
