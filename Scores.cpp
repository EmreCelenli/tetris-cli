#include "Scores.hpp"

Score::Score(){
        score = 0;
        clear_lines = 0;
}

void Score::update_score(int l){
    clear_lines = clear_lines + l;
    switch (l) {
        case 1:
            score = score + 10;
            break;
        case 2:
            score = score + 30;
            break;
        case 3:
            score = score + 50;
            break;
        case 4:
            score = score + 100;
            break;
        default:
            break;
    
    }
}

void Score::display_score(WINDOW * win){
        mvwprintw(win, 0, 0, "Score:%d", score);
        wrefresh(win);
        mvwprintw(win, 1, 0, "Lines Cleared:%d", clear_lines);
        wrefresh(win);
}

int Score::get_clearlines(){
        return clear_lines;
}

int Score::get_score(){
        return score;
}

void Score::get_score_str(char score_str[100]) {
        sprintf(score_str, "%d", score);
}
