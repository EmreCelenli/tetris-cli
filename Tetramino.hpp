#include "ncurses.h"
#include <cstdlib>
#include <ctime>

struct point{
    int y, x;
};

const point defaultMatrix[2][4] = {
    {{0, 4}, {0, 3}, {0, 5}, {0, 6}},
    {{0, 4}, {0, 5}, {1, 4}, {1, 5}}
};

class Tetramino{
    protected:
        int id;
        point block[4]; // l'origine del tetramino è sempre block[0]
    public:
        Tetramino();
        void getCoordinates(point []);
        void move(int);
};