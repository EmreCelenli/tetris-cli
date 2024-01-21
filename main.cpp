#include "main.hpp"

int main(){
    initscr();
    noecho();
    curs_set(0);

    int sel;

    do{
        sel = menu(stdscr);

        if(sel == 0)
            game(stdscr);
        else if(sel == 1)
            scores(stdscr);
        
    }while(sel != 2);


    endwin();
}