#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include <algorithm>

using namespace std;

class Point {
private:
  double x, y;

public:
  Point();
  Point(double, double);
  Point(const Point&);

  double getX() const;
  double getY() const;

  bool operator== (const Point &);
  bool operator< (const Point &);
};

Point::Point() {
  x = y = 0;
}

Point::Point(double xx, double yy) {
  x = xx;
  y = yy;
}

Point::Point(const Point &other) {
  x = other.x;
  y = other.y;
}

double Point::getX() const {
  return x;
}

double Point::getY() const {
  return y;
}

bool Point::operator== (const Point &other) {
  return (x == other.x && y == other.y);
}

bool Point::operator< (const Point &other) {
  if (x == other.x) {
    return (y > other.y);
  } else {
    return (x > other.x);
  }
}

ostream& operator<< (ostream &out, const Point &obj) {
  out << "(" << obj.getX() << "," << obj.getY() << ")";
  return out;
}

int main(int argc, char* argv[]) {
  Point a(1, 1);
  Point b(1, 2);
  Point c(1, 1);
  list<Point> points;

  /*
  cout << "a = " << a << "\n";
  cout << "b = " << b << "\n";
  cout << "c = " << c << "\n";

  cout << "a == b? " << (a == b) << "\n";
  cout << "a == c? " << (a == c) << "\n";
  */

  srand(1234);
  for (int i = 0; i < 10; i++) {
    points.push_back(Point(rand() % 100, rand() % 100));
  }

  points.sort();
  for (Point p : points) {
    cout << p << "\n";
  }

  list<Point>::iterator it = find(points.begin(), points.end(), a);
  cout << "find(points.begin(), points.end(), a)? " << (it != points.end()) << "\n";
  return 0;
}
