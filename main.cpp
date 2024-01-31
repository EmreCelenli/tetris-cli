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
            
            WINDOW * gridwin = newwin(20, 10, 0, 0);
            Grid grid(gridwin);
            grid.displayGrid();
            int direction = wgetch(gridwin);
            grid.moveDirection(direction);
            wgetch(gridwin);

            
            getch();
        }

    }while(sel != 2);


    endwin();

    return 0;
}