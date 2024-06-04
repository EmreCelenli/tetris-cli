#include <ncurses.h>
#include <fstream>
#include <string>
#include <cstring>

class Menu{
    protected:
        WINDOW * win;
        std::string choices[3] = {"NUOVA PARTITA", "CLASSIFICA", "ESCI"};
        int xMax, yMax;
        int xHalf, yHalf;
        int highlight;
    public:
        Menu(WINDOW *);
        int getChoice();
};