#include <ncurses.h>

class Score{

private:
    int score;
    int clear_lines;
public:

    Score(){
        score = 0;
        clear_lines = 0;
    }

    void update_score(int l = 0){
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

    void display_score(){
        mvprintw(0, 0, "Score:%d", score);
        mvprintw(1, 0, "Lines Cleared:%d", clear_lines);
        refresh();
    }

    int get_clearlines(){
        return clear_lines;
    }

    int get_score(){
        return score;
    }


};


class Classifica: public Score{
protected:
    WINDOW *win;
    int scores[10];
    int count;
public:
    Classifica(int score, int clear_lines, int scores[10], int count, WINDOW *win): Score(){
        for (int i = 0; i < 10; i++){
            this->scores[i] = scores[i];
        }
        
        this->count = 1;
        this->win = win;
    }

    // Swap function for Score class.    

   void swap(int &x, int &y){
        int tmp = x;
        x = y;
        y = tmp;
   }

    // Using Bubble Sort algorithm with Invert function. 

   void bubble_sort(int scores[10]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; i < 10-i-1; j++){
            if(scores[j] > scores[j+1]){
                swap(scores[j], scores[j+1]);
            }
            
        }
    }
   }     

    void invert_sorted(int scores[10]){
        for(int i = 0; i < 5; i++){
            swap(scores[i], scores[10-1-i]);
        }
    }

    
    void display_classifica(){
        mvprintw(3, 3, "Classifica:%d", scores);
        refresh();
    }

};


