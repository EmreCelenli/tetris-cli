#include <ncurses.h>
#include <unistd.h>
#include "Tetramino.hpp"

class Grid{
    protected:
        WINDOW * win;
        Tetramino block;
        bool grid[20][10];
        //int removedLines;
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