// =================================================================
// File: vector.h
// Author: Pedro Perez
// Description: This file contains the implementation of a vector of 
//				integers.
//
// Copyright (c) 2024 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

using namespace std;

class Vector {
private: 
    int *data;
    int size;

public:
    Vector();
    Vector(unsigned int);
    Vector(unsigned int, int);
    Vector(const Vector&);

    ~Vector();

    unsigned int length() const;

    int& operator[](unsigned int);

    void resize(unsigned int);
    void resize(unsigned int, int);
};

// =================================================================
// Constructor. Creates a vector with a default size = 1.
// =================================================================
Vector::Vector() {
    size = 1;
    data = new int[size];
}

// =================================================================
// Constructor. Receives the initial size of the Vector.
//
// @param s the initial size of the Vector.
// =================================================================
Vector::Vector(unsigned int s) {
    size = s;
    data = new int[size];
}

// =================================================================
// Constructor. Receives the initial size of the Vector.
//
// @param s     the initial size of the Vector.
// @param val   the initial value for each cell.
// =================================================================
Vector::Vector(unsigned int s, int val) {
    size = s;
    data = new int[size];

    for (unsigned int i = 0; i < size; i++) {
        data[i] = val;
    }
}

// =================================================================
// Copy constructor. It will create a copy of the source Vector.
//
// @param source    the Vector of which it will create a copy.
// =================================================================
Vector::Vector(const Vector &v) {
    size = v.size;
    data = new int[size];

    for (unsigned int i = 0; i < size; i++) {
        data[i] = v.data[i];
    }
}

// =================================================================
// Destructor. Free the memory space used by the class.
// =================================================================
Vector::~Vector() {
    delete [] data;
    data = 0; // NULL, nullptr
    size = 0;
}


// =================================================================
// Return the size of the Vector.
// @return the new Vector size.
// =================================================================
unsigned int Vector::length() const {
    return size;
}

int& Vector::operator[](unsigned int index){
    return data[index];
}

// =================================================================
// Resize the Vector. If thew new size is less than the original
// size, only copy the first elements. Otherwise, copy all the values.
//
// @param newSize   The new size of the Vector.
// =================================================================
void Vector::resize(unsigned int newSize) {
    if (size == newSize) {
        return; 
    }
    
    int *newData = new int[newSize];
    unsigned int limit = (size < newSize)? size : newSize;
    /*
    int limit;
    if (size < newSize) {
        limit = size;
    } else {
        limit = newSize;
    }
    */
   /*
   limit = size;
   if (newSize < size) {
    limit = newSize;
   }
   */

    for (unsigned int i = 0; i < limit; i++) {
        newData[i] = data[i];
    }

    delete [] data;
    data = newData;
    size = newSize;
}

// =================================================================
// Resize the Vector. If thew new size is less than the original
// size, only copy the first elements. Otherwise, copy all the 
// values. If the new size is larger, initialize the new cells 
// with the value received.
//
// @param newSize   The new size of the Vector.
// @param val       The value for the new cells.
// =================================================================
void Vector::resize(unsigned int newSize, int val) {
    if (size == newSize) {
        return; 
    }

    int *newData = new int[newSize];
    int limit = (size < newSize)? size : newSize;
    
    for (int i = 0; i < limit; i++) {
        newData[i] = data[i];
    }
    delete [] data;
    data = newData;
    size = newSize;

    for (int i = limit; i < size; i++) {
        data[i] = val;
    }
}

ostream& operator<< (ostream& out, Vector &v) {
    out << v[0];
    for (unsigned int i = 1; i < v.length(); i++) {
        out << " " << v[i];
    }
    return out;
}
#endif


