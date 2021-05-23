/*************************************************************
* File: utils.h
* Author: Pedro Perez
* Description: This file contains the implementation of
*              basic functions used in the project.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#include "utils.h"

std::vector<std::string> split(std::string input, char sep) {
  std::vector<std::string> result;
  std::stringstream in(input);
  std::string aux;

  while (in.good() ) {
    getline(in, aux, sep);
    result.push_back(aux);
  }
  return result;
}
