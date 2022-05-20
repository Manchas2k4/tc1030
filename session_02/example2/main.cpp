#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "rational.h"

using namespace std;

int main(int argc, char* argv[]) {
  ifstream inputFile;
  ofstream outputFile;
  int n, num1, den1, num2, den2, op;
  Rational a, b, c;
  bool result;

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

    a = Rational(num1, den1);
    b = Rational(num2, den2);

    switch(op) {
      case 1: c = a.add(b); outputFile << c.getNumerator() << "/" << c.getDenominator() << "\n"; break;
      case 2: c = a.sub(b); outputFile << c.getNumerator() << "/" << c.getDenominator() << "\n"; break;
      case 3: c = a.mult(b); outputFile << c.getNumerator() << "/" << c.getDenominator() << "\n"; break;
      case 4: c = a.div(b); outputFile << c.getNumerator() << "/" << c.getDenominator() << "\n"; break;
      case 5: outputFile << ((a.equals(b))? "true" : "false") << "\n"; break;
      case 6: outputFile << ((a.less(b))? "true" : "false") << "\n"; break;
    }
  }

  /*
  int x = 5, y;
  if (x < 5) {
    y = 0;
  } else {
    y = 1;
  }

  y = (x < 5)? 0 : 1;
  */

  inputFile.close();
  outputFile.close();
  return 0;
}
