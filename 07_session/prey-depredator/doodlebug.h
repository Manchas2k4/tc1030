#ifndef DOODLEBUG_H
#define DOODLEBUG_H

#include "header.h"

class DoodleBug : public Organism {
protected:
    int starving;

public:
    DoodleBug();
    DoodleBug(int, int);
    DoodleBug(const DoodleBug&);

    void move();
    void breed();
    void starve();
};

DoodleBug::DoodleBug() : Organism(DOODLEBUG), starving(-1) {}

DoodleBug::DoodleBug(int r, int c) 
    : Organism(r, c, BREED_DOODLEBUG, DOODLEBUG), 
      starving(STARVE_DOODLEBUG) {}
    
DoodleBug::DoodleBug(const DoodleBug &d) 
    : Organism(d), starving(STARVE_DOODLEBUG) {}

void DoodleBug::move() {
    int newRow, newCol;
    bool hasEaten = false;

    if (hasMoved) {
        return;
    }

    random_shuffle(options, options+3);
    for (pair<int, int> p : options) {
        newRow = row + p.first;
        newCol = col + p.second;
        if (isValid(newRow, newCol) && !isEmpty(newRow, newCol) &&
            theWorld[newRow][newCol]->getType() == ANT) {
            // SE COME A LA HORMIGA
            delete theWorld[newRow][newCol];
            theWorld[newRow][newCol] = 0;

            // SE CAMBIA DE LUGAR
            theWorld[row][col] = 0; // NULL, nullptr
            
            row = newRow; 
            col = newCol;
            theWorld[row][col] = this;

            // INDICA QUE YA COMIO
            starving = STARVE_DOODLEBUG;
            hasEaten = true;

            break;
        }
    }

    if (!hasEaten) {
        for (pair<int, int> p : options) {
            newRow = row + p.first;
            newCol = col + p.second;
            if (isValid(newRow, newCol) && isEmpty(newRow, newCol)) {
                // SE CAMBIA DE LUGAR
                theWorld[row][col] = 0; // NULL, nullptr
                
                row = newRow; 
                col = newCol;
                theWorld[row][col] = this;

                break;
            }
        }
        starving--;
    }
    
    hasMoved = true;
    breeding--;
}

void DoodleBug::breed() {
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
                theWorld[newRow][newCol] = new DoodleBug(newRow, newCol);

                break;
            }

        }
        breeding = BREED_DOODLEBUG;
    }
}

void DoodleBug::starve() {
    if (starving == 0) {
        int i = row, j = col;

        delete theWorld[i][j];
        theWorld[i][j] = 0;
    }
}

#endif