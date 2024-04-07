#include "ncurses.h"
#include <cstdlib>
#include <ctime>

struct point{
    int y, x;
};

const point defaultMatrix[7][4] = {
    {{0, 4}, {0, 3}, {0, 5}, {0, 6}}, // 1x4
    {{0, 4}, {0, 5}, {1, 4}, {1, 5}}, // 2x2
    {{0, 4}, {0, 3}, {1, 4}, {1, 5}}, // snake
    {{0, 5}, {0, 6}, {1, 5}, {1, 4}}, // snake 2
    {{1, 4}, {0, 3}, {1, 3}, {1, 5}}, // L 
    {{1, 5}, {1, 6}, {1, 4}, {0, 6}}, // L 2
    {{1, 4}, {0, 4}, {1, 3}, {1, 5}}, // T   
};

class Tetramino{
    protected:
        int id;
        point block[4]; // l'origine del tetramino è sempre block[0]
    public:
        Tetramino();
        void getCoordinates(point []);
        void move(int);
        void rotate(bool);
        void insert(point []);
        void convertCoordinates(point [], point []);
        int getID();
        int isOut();
};