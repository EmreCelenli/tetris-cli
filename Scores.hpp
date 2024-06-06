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

