#include <ncurses.h>
#include <cstdlib>
#include "Scores.hpp"

class Classifica{
    protected:
        WINDOW *win;
        int scores[10];
    public:
        Classifica(WINDOW *, int);
        void update_classifica(int);
        void display_classifica();
        void write_classifica();
        void read_classifica();
};