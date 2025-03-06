#ifndef ANT_H
#define ANT_H

#include "header.h"

class Ant : public Organism {
public:
    Ant();
    Ant(int, int);
    Ant(const Ant&);

    void move();
    void breed();
};

Ant::Ant() : Organism(ANT) {}

Ant::Ant(int r, int c) : Organism(r, c, BREED_ANT, ANT) {
}

Ant::Ant(const Ant &a) : Organism(a) {}

void Ant::move() {
    int newRow, newCol;

    if (hasMoved) {
        return;
    }

    random_shuffle(options, options+3);
    for (pair<int, int> p : options) {
        newRow = row + p.first;
        newCol = col + p.second;
        if (isValid(newRow, newCol) && isEmpty(newCol, newRow)) {
            theWorld[row][col] = 0; // NULL, nullptr
            
            row = newRow; 
            col = newCol;
            theWorld[row][col] = this;

            break;
        }
    }

    hasMoved = true;
    breeding--;
}

void Ant::breed() {
    int newRow, newCol;

    if (hasMoved) {
        hasMoved = false;
    }

    if (breeding == 0) {
        random_shuffle(options, options+3);
        for (pair<int, int> p : options) {
            newRow = row + p.first;
            newCol = col + p.second;

            if (isValid(newRow, newCol) && isEmpty(newRow, newCol)) {
                theWorld[newRow][newCol] = new Ant(newRow, newCol);
                
                break;
            }

        }
        breeding = BREED_ANT;
    }
}
#endif