#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <utility>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <ctime>

using namespace std;

const int ROWS = 20;
const int COLS = 20;
const int BREED_ANT = 3;
const int BREED_DOODLEBUG = 8;
const int STARVE_DOODLEBUG = 5;
const int MAX_ITERATIONS = 100;

pair<int, int> options[4] = { {-1, 0}, {0, +1}, {+1, 0}, {0, -1} }; 

typedef enum {NONE, ANT, DOODLEBUG} Type;

class Organism {
protected:
    int row, col, breeding;
    Type type;
    bool hasMoved;

public:
    Organism();
    Organism(Type);
    Organism(int, int, int, Type);
    Organism(const Organism&);

    Type getType() const;
    
    virtual void move() = 0;
    virtual void breed() = 0;
};

Organism::Organism() 
    : row(-1), col(-1), breeding(-1), type(NONE), hasMoved(false) {}

Organism::Organism(Type t) 
    : row(-1), col(-1), breeding(-1), type(t), hasMoved(false) {}

Organism::Organism(int r, int c, int b, Type t) 
    : row(r), col(c), breeding(b), type(t), hasMoved(false) {}

Organism::Organism(const Organism& o) 
    : row(o.row), col(o.col), breeding(o.breeding), 
      type(o.type), hasMoved(o.hasMoved) {}

Type Organism::getType() const {
    return type;
}

Organism* theWorld[ROWS][COLS];

bool isValid(int row, int col) {
    return (row >= 0 && row < ROWS && 
            col >= 0 && col < COLS);
}

bool isEmpty(int row, int col) {
    return (theWorld[row][col] == 0);
}

#endif