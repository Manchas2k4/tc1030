#ifndef SET_H
#define SET_H

#include <iostream>
#include <sstream>

using namespace std;

typedef unsigned uint;

class Set {
private:
	bool *numbers;
	uint  size;

public:
	Set(uint max);
	Set(const Set &s);
	~Set();

	bool add(uint number);
	bool remove(uint number);
	Set* join(const Set &b);
	Set* intersection(const Set &b);
	Set* diference(const Set &b);

	string toString() const;
};

Set::Set(uint max) {
	size = max;
	numbers = new bool[size + 1];
	for (int i = 1; i <= size; i++) {
		numbers[i] = false;
	}
}

Set::Set(const Set &s) {
	size = s.size;
	numbers = new bool[size];
	for (int i = 1; i <= size; i++) {
		numbers[i] = s.numbers[i];
	}
}

Set::~Set() {
	delete [] numbers;
}

bool Set::add(uint number) {
	if (number > size) {
		return false;
	} 
	
	numbers[number] = true;
	return true;
}

bool Set::remove(uint number) {
	if (number > size) {
		return false;
	} 
	
	numbers[number] = false;
	return true;
}

Set* Set::join(const Set &b) {
	int i;
	int min = (size < b.size)? size : b.size;
	int max = (size > b.size)? size : b.size;

	Set *result = new Set(max);
	for (i = 1; i <= min; i++) {
		if (numbers[i] == true || b.numbers[i] == true) {
			result->numbers[i] = true;
		}
	}

	if (size < b.size) {
		for (; i <= b.size; i++) {
			result->numbers[i] = b.numbers[i];
		}
	} else {
		for (; i <= size; i++) {
			result->numbers[i] = numbers[i];
		}
	}
	return result;
}

Set* Set::intersection(const Set &b) {
	/*
	if (size != b.size) {
		return NULL;
	} else {
		Set *result = new Set(size);
		for (int i = 0; i < size; i++) {
			result->numbers[i] = numbers[i] && b.numbers[i];
		}
		return result;
	}
	*/
	/*
	int min = 0;
	if (size < b.size) {
		min = size;
	} else {
		min = b.size;
	}
	*/

	// x = (cond)? si_true : si_false
	int min = (size < b.size)? size : b.size;
	Set *result = new Set(min);
	for (int i = 1; i <= min; i++) {
		result->numbers[i] = numbers[i] && b.numbers[i];
	}
	return result;
}

Set* Set::diference(const Set &b) {
	int max = (size > b.size)? size : b.size;
	Set *result = new Set(max);
	for (int i = 0; i <= max; i++) {
		if (numbers[i] == true && b.numbers[i] == false) {
			result->numbers[i] = true;
		}
	}
	return result;
}

string Set::toString() const {
	stringstream aux;

	aux << "(";
	for (int i = 1; i <= size; i++) {
		if (numbers[i] == true) {
			aux << i << " ";
		}
	}
	aux << ")";
	return aux.str();
}
#endif