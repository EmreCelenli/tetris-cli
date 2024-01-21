#include "menu.hpp"

int menu(WINDOW * win){

    int ch;
    int xMax, yMax;
    getmaxyx(win, yMax, xMax);
    const int xHalf = xMax/2;
    const int yHalf = yMax/2;

    string choices[3] = {"NUOVA PARTITA", "CLASSIFICA", "ESCI"};
               
    int highlight = 0;       

    keypad(win, true);
    

    while(1){
        int x[3] = {xHalf - 6, xHalf - 5, xHalf - 2};
        int y = yHalf - 2;

        for(int i = 0; i < 3; i++){
            if(i == highlight){
                wattron(win, A_BOLD);
                wattron(win, A_ITALIC);
            }
            mvwprintw(win, y, x[i], choices[i].c_str());
            wattroff(win, A_BOLD);
            wattroff(win, A_ITALIC);
            refresh();
            y += 2;
        }
        
        ch = wgetch(win);
        
        switch(ch){
        case KEY_UP:
            if(highlight == 0)
                highlight = 2;
            else
                highlight--;    
            break;
        case KEY_DOWN:
            if(highlight == 2)
                highlight = 0;
            else
                highlight++; 
            break;
        default:
            break;
        }

        if(ch == 10){
            break;
        }
    }

    return highlight;
}