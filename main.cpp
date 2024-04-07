#include "Menu.hpp"
#include "Grid.hpp"

int main(){
    initscr();
    noecho();
    curs_set(0);

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
            Grid grid(gridwin);
            keypad(gridwin, true);
            grid.displayGrid();
            grid.game();
            
           
            
            getch();
        }

    }while(sel != 2);


    endwin();

    return 0;
}