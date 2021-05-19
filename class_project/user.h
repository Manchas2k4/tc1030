/*************************************************************
* File: user.h
* Author: Pedro Perez
* Description: This file contains the definition of User class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/

#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <sstream>
#include "types.h"

#define MAXBORROWEDITEMS  5

class User {
private:
    uint id;
    std::string name;
    uint amountBorrowedItems;
    double fine;

public:
  User();
  User(uint, std::string);
  User(uint, std::string, uint, double);
  User(const User&);

  uint getId() const;
  std::string getName() const;
  uint geAmountBorrowedItems() const;
  double getFine() const;

  void setId(uint);
  void setName(std::string);
  void setAmountBorrowedItems(uint);
  void setFine(double);

  std::string toString() const;
};

#endif
