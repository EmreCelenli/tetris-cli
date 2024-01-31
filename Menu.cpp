#include "Menu.hpp"

Menu::Menu(WINDOW * win){
    this->win = win;
    getmaxyx(this->win, yMax, xMax);
    highlight = 0;
    xHalf = xMax/2;
    yHalf = yMax/2;
}

int Menu::getChoice(){
    
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
            wrefresh(win);
            y += 2;
        }
        
        int ch = wgetch(win);
        
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

        if(ch == 10) 
            return highlight;
            
    }
}