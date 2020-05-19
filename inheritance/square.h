#ifndef SQUARE_H
#define SQUARE_H

class Square : public Rectangle {
public:
	Square();
	Square(float l);
};

Square::Square() 
	: Rectangle() {
}

Square::Square(float l) 
	: Rectangle(l, l){	
}

#endif