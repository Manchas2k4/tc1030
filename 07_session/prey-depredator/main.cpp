#include "header.h"
#include "ant.h"
#include "doodlebug.h"

void init() {
    int i, row, col;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            theWorld[i][j] = 0;
        }
    }

    i = 10;
    while(i >= 0) {
        row = rand() % ROWS;
        col = rand() % COLS;

        if (isEmpty(row, col)) {
            theWorld[row][col] = new Ant(row, col);
            i--;
        }
    }


    i = 10;
    while(i >= 0) {
        row = rand() % ROWS;
        col = rand() % COLS;

        if (isEmpty(row, col)) {
            theWorld[row][col] = new DoodleBug(row, col);
            i--;
        }
    }
}

void display() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (!isEmpty(i, j)) {
                switch(theWorld[i][j]->getType()) {
                    case ANT        : cout << "O"; break;
                    case DOODLEBUG  : cout << "X"; break;
                }
            } else {
                cout << "-";
            }
        }
        cout << "\n";
    }
}

int main(int argc, char* argv[]) {
    srand(time(0));
    char c;

    init();
    for (int k = 0; k < MAX_ITERATIONS; k++) {
        cout << "Iteration " << k << ":\n";
        display();

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (!isEmpty(i,j)) {
                    theWorld[i][j]->move();
                }
            }
        }

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (!isEmpty(i,j)) {
                    theWorld[i][j]->breed();
                }
            }
        }

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (!isEmpty(i,j) && theWorld[i][j]->getType() == DOODLEBUG) {
                    ((DoodleBug*) theWorld[i][j])->starve();
                }
            }
        }
        
        c = getchar();
    }

    return 0;
}