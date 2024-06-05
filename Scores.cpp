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
/*
Classifica::Classifica(int score, int clear_lines, int scores[10], int count, WINDOW *win): Score(){
        for (int i = 0; i < 10; i++){
            this->scores[i] = scores[i];
        }
        
        this->count = 1;
        this->win = win;
}
    
void Classifica::update_classifica(int score) {
    for(int i = 0; i < 100; i++){

    }

    /*
    int index = 0;
    while (index < 10 && scores[index] >= score) {
        index++;
    }

    for (int i = 9; i > index; i--) {
        scores[i] = scores[i - 1];
    }
    scores[index] = score;
    this->clear_lines = clear_lines;
    
}


void Classifica::display_classifica() {
    mvwprintw(win, 3, 3, "Scores:");
    for (int i = 0; i < 10; i++) {
        mvwprintw(win, 4 + i, 3, "%d. %d", i + 1, scores[i]);
    }
    wrefresh(win);
    wgetch(win);
}
    
    
// Swap function for Score class.    

void Classifica::swap(int &x, int &y){
    int tmp = x;
    x = y;
    y = tmp;
}

// For the sorting algorithm, i choose insertion sort because of it's cache efficiency in a small input data. Complexity o(n^2)

void Classifica::insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void Classifica::invert_sorted(int scores[10]){
    for(int i = 0; i < 5; i++){
        swap(scores[i], scores[10-i-1]);
    }
}

*/
