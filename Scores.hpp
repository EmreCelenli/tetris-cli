#include <ncurses.h>


class Score{
    protected:
        int score;
        int clear_lines;
    public:
        Score();
        void update_score(int);
        void display_score(WINDOW *);
        int get_clearlines();
        int get_score();
        void get_score_str(char[]);
};

/*
// Sottoclasse

class Classifica: public Score{
    protected:
        WINDOW *win;
        int scores[10];
        int count;
    public:
        Classifica(int, int, int[], int, WINDOW *);
        void update_classifica(int);
        void display_classifica();
        void swap(int&, int&);
        void insertion_sort(int[], int);
        void invert_sorted(int[]);
};
*/

