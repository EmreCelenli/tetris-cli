#include "Menu.hpp"
#include "Grid.hpp"
#include "Classifica.hpp"


using namespace std;

int main(){
    initscr();
    noecho();
    curs_set(0);

    WINDOW * classificawin = newwin(22, 22, 0, 0);
    Classifica classifica(classificawin);
    if(!classifica.fileExists()){
        classifica.initialize_classifica();
    }

    int sel;

    do{

        WINDOW * menuwin = newwin(getmaxy(stdscr), getmaxx(stdscr), 0, 0);

        Menu menu(menuwin);
        sel = menu.getChoice();
        

        if(sel == 0){
            wclear(menuwin);
            wrefresh(menuwin);
            delwin(menuwin);
            refresh();
            WINDOW * boxwin = newwin(22, 22, 0, 0);
            box(boxwin, 0, 0);
            wrefresh(boxwin);
            WINDOW * gridwin = newwin(20, 20, 1, 1);
            srand(time(0));
            Grid grid(gridwin);
            keypad(gridwin, true);
            grid.displayGrid();
            WINDOW * scorewin = newwin(30, 30, 0, 23);
            int gamescore = grid.game(scorewin);
            classifica.update_classifica(gamescore);
            getch();
        }

        if(sel == 1){
            wclear(menuwin);
            wrefresh(menuwin);
            delwin(menuwin);
            refresh();
            cbreak();
            classifica.display_classifica();
        }

    } while(sel != 2);

    endwin();

    return 0;
}
    