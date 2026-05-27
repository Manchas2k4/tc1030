// =================================================================
//
// File: vector.h
// Author: Pedro Perez
// Description: This file contains the implementation of the
//				IntegersVector class.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#ifndef VECTOR_H
#define VECTOR_H

#include "exception.h"
#include <string>
#include <sstream>

typedef unsigned int uint;

class IntegersVector {
private:
	uint size;
	int	*data;

public:
	IntegersVector();
	IntegersVector(uint);
	IntegersVector(uint, int);
	IntegersVector(const IntegersVector&);
	~IntegersVector();

	uint length() const;
	uint resize(uint);
	std::string toString() const;

	int& operator[](uint) const;
	IntegersVector& operator=(const IntegersVector&);
};

// =================================================================
// Constructor. Creates a IntegersVector with a default size = 1.
//
// @throws there is not enough memory space for the IntegersVector.
// =================================================================
IntegersVector::IntegersVector() {
	size = 1;
	data = new int[size];
	if(data == 0){
		throw OutOfMemory();
	}
}

// =================================================================
// Constructor. Receives the initial size of the IntegersVector.
//
// @param numberOfElements initial size of the IntegersVector.
// @throws when the location number is zero or there is not enough
// 		   memory space for the IntegersVector.
// =================================================================
IntegersVector::IntegersVector(uint elements) {
	if(elements == 0){
		throw RangeError();
	}

	size = elements;
	data = new int[size];
	if(data == 0){
		throw OutOfMemory();
	}
}

// =================================================================
// Constructor. Receives the initial size of the IntegersVector.
//
// @param numberOfElements initial size of the IntegersVector.
// @throws when the location number is zero or there is not enough
// 		   memory space for the IntegersVector.
// =================================================================
IntegersVector::IntegersVector(uint elements, int initialValue) {
	if(elements == 0){
		throw RangeError();
	}
	size = elements;
	data = new int[size];
	if(data == 0){
		throw OutOfMemory();
	}
	for (uint i = 0; i < size; i++) {
		data[i] = initialValue;
	}
}

// =================================================================
// Copy constructor. It will create a copy of the source IntegersVector.
//
// @param source the IntegersVector of which it will create a copy.
// @throws when there is not enough memory space.
// =================================================================
IntegersVector::IntegersVector(const IntegersVector &source) {
	size = source.size;
	data = new int[size];
	if(data == 0){
		throw OutOfMemory();
	}
	for(uint i = 0; i < size; i++){
		data[i] = source.data[i];
	}
}


// =================================================================
// Destructor. Free the memory space used by the class.
// =================================================================
IntegersVector::~IntegersVector() {
	delete [] data;
	data = 0;
	size = 0;
}

// =================================================================
// Return the size of the IntegersVector.
// =================================================================
uint IntegersVector::length() const {
	return size;
}

// =================================================================
// Resize the IntegersVector. If thew new size is less than the original
// size, only copy the first element. Otherwise, copy all the values.
//
// @param newSize the new size of the IntegersVector.
// @return the new IntegersVector size.
// @throws when there is not enough memory space.
// =================================================================
uint IntegersVector::resize(uint newSize) {
	if (newSize == 0){
		throw RangeError();
	}

	if (size == newSize) {
		return size;
	}

	int *newData = new int[newSize];
	if(newData == 0){
		throw OutOfMemory();
	}

	if(newSize < size){
		for(uint i = 0; i < newSize; i++) {
			newData[i] = data[i];
		}
	} else{
		for(uint i = 0; i < size; i++) {
			newData[i] = data[i];
		}
	}

	delete [] data;
	data = newData;
	size = newSize;

	return size;
}

// =================================================================
// Return the string representation of the IntegersVector.
//
// @return a string representation.
// =================================================================
std::string IntegersVector::toString() const {
	std::stringstream aux;

	aux << "[" << data[0];
	for (uint i = 1; i < size; i++) {
		aux << ", " << data[i];
	}
	aux << "]";
	return aux.str();
}

// =================================================================
// Overload the operator [] to operate with the IntegersVector class.
//
// @param index a valid position of the IntegersVector.
// @return the value, by reference, which is in the position
//		   indicated by index.
// @throws when the index is invalid.
// =================================================================
int& IntegersVector::operator[] (uint index) const {
	if(index >= size){
		throw IndexOutOfBounds();
	}
	return data[index];
}

// =================================================================
// Overload the assignment operator. Make an identical copy of the
// source IntegersVector.
//
// @param source the IntegersVector to be copied
// =================================================================
IntegersVector& IntegersVector::operator=(const IntegersVector &right) {
	if(size != right.size){
		resize(right.size);
	}
	for(uint i =0; i < right.size; i++){
		data[i] = right.data[i];
	}
	return (*this);
}

#endif /* IntegersVector_H */
