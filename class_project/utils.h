/*************************************************************
* File: utils.h
* Author: Pedro Perez
* Description: This file contains the basic data types and
*              functions used in the project.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream> // files
#include <sstream>
#include<limits>
#include <vector>

typedef unsigned int uint;
typedef unsigned char uchar;

typedef enum {NONE, BOOK, SCROLL, ORB} ItemType;

const int MAXSIZE = 100;
const int MAXBORROWEDITEMS = 5;

std::vector<std::string> split(std::string, char sep=',');

#endif
