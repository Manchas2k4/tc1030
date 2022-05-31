#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <list>
#include <algorithm>
#include "rational.h"

using namespace std;

int main(int argc, char* argv[]) {
  ifstream inputFile;
  ofstream outputFile;
  int n, num1, den1, num2, den2, op;
  Rational a, b, c;
  bool result;
  list<Rational> rationals;

  if (argc != 3) {
    cout << "usage: " << argv[0] << " input_file output_file\n";
    return -1;
  }

  inputFile.open(argv[1]);
  if (!inputFile.is_open()) {
    cout << argv[0] << ": File \"" << argv[1] << "\" not found\n";
    return -1;
  }

  outputFile.open(argv[2]);

  inputFile >> n;
  for (int i = 0; i < n; i++) {
    inputFile >> op >> num1 >> den1 >> num2 >> den2;

    a = Rational(num1, den1); rationals.push_back(a);
    b = Rational(num2, den2); rationals.push_back(b);

    switch(op) {
      case 1: c = a + b; rationals.push_back(c); outputFile << c << "\n"; break;
      case 2: c = a - b; rationals.push_back(c); outputFile << c << "\n"; break;
      case 3: c = a * b; rationals.push_back(c); outputFile << c << "\n"; break;
      case 4: c = a / b; rationals.push_back(c); outputFile << c << "\n"; break;
      case 5: outputFile << ((a == b)? "true" : "false") << "\n"; break;
      case 6: outputFile << ((a < b)? "true" : "false") << "\n"; break;
    }
  }

  outputFile << "Unordered:\n";
  for (Rational r : rationals) {
    outputFile << r << " ";
  }
  outputFile << "\n";

  rationals.sort();

  outputFile << "Ordered:\n";
  for (Rational r : rationals) {
    outputFile << r << " ";
  }
  outputFile << "\n";

  list<Rational>::iterator itr;
  itr = find(rationals.begin(), rationals.end(), Rational(4, 2));
  outputFile << "\nSearching for 4/2: ";
  if (itr != rationals.end()) {
    outputFile << "true value = " << (*itr) << "\n";
  } else {
    outputFile << "false value = " << (*itr) << "\n";
  }

  itr = find(rationals.begin(), rationals.end(), Rational(1, 3));
  outputFile << "\nSearching for 1/3: ";
  if (itr != rationals.end()) {
    outputFile << "true value = " << (*itr) << "\n";
  } else {
    outputFile << "false value = " << (*itr) << "\n";
  }

  inputFile.close();
  outputFile.close();
  return 0;
}
