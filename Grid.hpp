#include <ncurses.h>
#include <unistd.h>
#include "Tetramino.hpp"

#define WIDTH 10
#define HEIGHT 20

class Grid{
    protected:
        WINDOW * win;
        Tetramino block;
        bool grid[HEIGHT][WIDTH];
    public:
        Grid(WINDOW *);
        void addBlock();
        void displayGrid();
        void removeBlock();
        bool checkDirection(int);
        void moveDirection(int);
        void moveDownDelayed(int);
        void rotation(bool);
        int game(WINDOW *);
        int removeLines();
        bool checkCompleted(int);
        bool checkBlockArea();
        void moveDownLines(int);
        int removeAllLines();
};