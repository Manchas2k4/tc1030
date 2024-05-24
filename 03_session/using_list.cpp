#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <list>
#include "circle.h"

using namespace std;

double averagePerimeter(const list<Circle> &circles) {
  double acum = 0;
  for (Circle c : circles) {
    acum += c.getPerimeter();
  }
  return (acum / circles.size());
}

void duplicateRadius(list<Circle> &circles) {
  list<Circle>::iterator itr;
  for (itr = circles.begin(); itr != circles.end(); itr++) {
    itr->setRadius(itr->getRadius() * 2);
  }
}

int main(int argc, char* argv[]) {
  ifstream inputFile;
  ofstream outputFile;
  int n, radius;
  list<Circle> circles;

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
    inputFile >> radius;
    circles.push_back(Circle(radius));
  }

  for (Circle c : circles) {
    outputFile << c.toString() << "\n";
  }

  outputFile << "Average perimeter = "
             << std::fixed << std::setprecision(2) << averagePerimeter(circles) << "\n";

  duplicateRadius(circles);

   for (Circle c : circles) {
     outputFile << c.toString() << "\n";
   }

  inputFile.close();
  outputFile.close();
  return 0;
}
