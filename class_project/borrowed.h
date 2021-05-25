/*************************************************************
* File: user.h
* Author: Pedro Perez
* Description: This file contains the definition of
*              BorrowedItem class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/

#ifndef BORROWED_H
#define BORROWED_H

#include "utils.h"
#include "date.h"

class BorrowedItem {
private:
  uint userId;
  uint itemId;
  Date startDate;
  uint maximumDays;

public:
  BorrowedItem();
  BorrowedItem(uint, uint, const Date&, uint);
  BorrowedItem(std::string);
  BorrowedItem(const BorrowedItem&);

  uint getUserId() const;
  uint getItemId() const;
  Date getStartDate() const;
  uint getMaximumDays() const;

  void setUserId(uint);
  void setItemId(uint);
  void setStartDate(const Date&);
  void setMaximumDays(uint);

  std::string toString() const;
};

#endif
