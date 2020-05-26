#include <iostream>

using namespace std;

const int SIZE = 40000000;

class Point {
private:
	int x, y;

public:
	Point();
	Point(int xx, int yy);
	void display() const;
};

Point::Point() {
	x = y = 0;
}

Point::Point(int xx, int yy) {
	x = xx;
	y = yy;
}

void Point::display() const {
	cout << "x = " << x << " y = " << y << "\n";
}

int main(int argc, char* argv[]) {
	/*
	Point objs[10];

	objs[0] = Point(10, 10);
	*/
	Point *objs = new Point[SIZE];
	
	for (int i = 0; i < SIZE; i++) {
		objs[i] = Point(i, i);
	}

	for (int i = 0; i < 20; i++) {
		objs[i].display();
	}

	delete [] objs;

	return 0;
}