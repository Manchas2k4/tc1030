#ifndef FIGURE_H
#define FIGURE_H

#include <string>

using namespace std;

class Figure {
protected:
	string type;

public:
	Figure();
	Figure(string t);
	string getType() const;
	virtual float getArea() const;
	virtual float getPerimeter() const;
	/*
	virtual float getArea() const = 0;
	virtual float getPerimeter() const = 0;
	*/
};

Figure::Figure() {
	type = "undefined";
}

Figure::Figure(string t) 
	: type(t) {
	// type = t;
}

string Figure::getType() const {
	return type;
}

float Figure::getArea() const {
	return 0;
}

float Figure::getPerimeter() const {
	return 0;
}
#endif