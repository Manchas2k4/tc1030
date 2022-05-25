// =========================================================
// File: circle.h
// Author:
// Date:
// Description:
// =========================================================
#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>
#include <sstream>
#include <iomanip>

const double PI = 3.141592653589793238;

class Circle {
private:
  int radius;

public:
  Circle();
  Circle(int);
  Circle(const Circle&);

  int getRadius() const;

  void setRadius(int);

  double getPerimeter() const;
  double getArea() const;

  std::string toString() const;
};

Circle::Circle() {
  radius = 1;
}

Circle::Circle(int r) {
  radius = r;
}

Circle::Circle(const Circle &c) {
  radius = c.radius;
}

int Circle::getRadius() const {
  return radius;
}

void Circle::setRadius(int r) {
  if (r < 1) {
    return;
  }
  radius = r;
}

double Circle::getPerimeter() const {
  return (2.0  * PI * radius);
}

double Circle::getArea() const {
  return (radius * radius * PI);
}

std::string Circle::toString() const {
  std::stringstream aux;

  aux << "Radius = " << std::fixed << std::setprecision(2) << radius << " "
      << "Perimeter = " << std::fixed << std::setprecision(2) << getPerimeter() << " "
      << "Area = " << std::fixed << std::setprecision(2) << getArea();
  return aux.str();
}


#endif
