#include <ncurses.h>
#include <cstdlib>
#include <fstream>
#include "Scores.hpp"

using namespace std;

class Classifica{
    protected:
        WINDOW *win;
        int scores[10];
    public:
        Classifica(WINDOW *);
        void update_classifica(int);
        void display_classifica();
        void write_classifica();
        void read_classifica();
        void initialize_classifica();
        bool fileExists();
};