#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <iostream>
#include <sstream>

using namespace std;

class BigInteger {
private:
	int *digits;
	int size;

public:
	BigInteger();
	BigInteger(string number);
	BigInteger(const BigInteger &b);
	~BigInteger();

	void add(const BigInteger &b);
	void add(const BigInteger &a, const BigInteger &b);
	string toString() const;
};

BigInteger::BigInteger() {
	size = 1;
	digits = new int[size];
	digits[0] = 0;
}

BigInteger::BigInteger(string number) {
	size = number.size();
	digits = new int[size];

	int i, j = 0; 
	for (i = size - 1; i >= 0; i--) {
		digits[j] = number[i] - '0';
		j++;
	}
}

BigInteger::BigInteger(const BigInteger &b) {
	size = b.size;
	digits = new int[size];
	for (int i = 0; i < size; i++) {
		digits[i] = b.digits[i];
	}
}

BigInteger::~BigInteger() {
	delete [] digits;
	digits = 0;
	size = 0;
}

void BigInteger::add(const BigInteger &b) {
	int minSize, maxSize, i, carry, sum;
	int *minDigits, *maxDigits, *newDigits;

	if (size < b.size) {
		minSize = size;
		minDigits = digits;
		maxSize = b.size;
		maxDigits = b.digits;
	} else {
		minSize = b.size;
		minDigits = b.digits;
		maxSize = size;
		maxDigits = digits;
	}

	newDigits = new int[maxSize + 1];

	carry = 0;
	for (i = 0; i < minSize; i++) {
		sum = carry + minDigits[i] + maxDigits[i];
		newDigits[i] = sum % 10;
		carry = sum / 10;
	}
	for (i = minSize; i < maxSize; i++) {
		sum = carry + maxDigits[i];
		newDigits[i] = sum % 10;
		carry = sum / 10;
	}
	newDigits[i] = carry;

	delete [] digits;
	digits = newDigits;
	size = maxSize + 1;
}

void BigInteger::add(const BigInteger &a, const BigInteger &b) {
	delete [] digits;

	size = a.size;
	digits = new int[size];
	for (int i = 0; i < size; i++) {
		digits[i] = a.digits[i];
	}

	add(b);
}

string BigInteger::toString() const {
	stringstream output;

	for (int i = size - 1; i >= 0; i--) {
		if ( (i != size - 1) || (digits[i] != 0) ) {
			output << digits[i];
		}
	}
	return output.str();
}
#endif











