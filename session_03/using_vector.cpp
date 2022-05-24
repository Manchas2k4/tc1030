#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "circle.h"

using namespace std;

double averagePerimeter(const vector<Circle> &circles) {
  double acum = 0;
  for (Circle c : circles) {
    acum += c.getPerimeter();
  }
  return (acum / circles.size());
}

void duplicateRadius(vector<Circle> &circles) {
  for (int i = 0; i < circles.size(); i++) {
    circles[i].setRadius(circles[i].getRadius() * 2);
  }
}

int main(int argc, char* argv[]) {
  ifstream inputFile;
  ofstream outputFile;
  int n, radius;
  vector<Circle> circles;

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

  circles.resize(n);
  for (int i = 0; i < n; i++) {
    inputFile >> radius;
    circles[i] = Circle(radius);
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
