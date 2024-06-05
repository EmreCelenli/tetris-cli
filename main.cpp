#include "Menu.hpp"
#include "Grid.hpp"
#include "Scores.hpp"
#include "Classifica.hpp"


using namespace std;

int main(){
    initscr();
    noecho();
    curs_set(0);

    WINDOW * classificawin = newwin(22, 22, 0, 0);
    Classifica classifica(classificawin);
    //int scores[10] = {0};
    //WINDOW* win = nullptr; 
    //int count = 0; 
    //Classifica classifica(score.get_score(), score.get_clearlines(), scores, count, win);   


    int sel;

    do{

        WINDOW * menuwin = newwin(getmaxy(stdscr), getmaxx(stdscr), 0, 0);

        Menu menu(menuwin);
        sel = menu.getChoice();
        //printw("%d", sel);
        //wrefresh(menuwin);
        //getch();


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
            WINDOW * scorewin = newwin(30, 30, 0, 23);
            //wprintw(scorewin, "%d", sel);
            //wrefresh(scorewin);
            int gamescore = grid.game(scorewin);
            classifica.update_classifica(gamescore);
            //int cleared_lines = score.get_clearlines();
            //score.update_score(cleared_lines);
            //classifica.update_classifica(score.get_score(), cleared_lines);
            //score.display_score(scorewin);
            char score_str[100];
            getch();
        }

        if(sel == 1){
            wclear(menuwin);
            wrefresh(menuwin);
            delwin(menuwin);
            refresh();
            WINDOW * boxwin = newwin(22, 22, 0, 0);
            box(boxwin, 0, 0);
            wrefresh(boxwin);
            
            // fstream
            char score_str[100];
            classifica.display_classifica();
            //score.get_score_str(score_str);

            /*
            ofstream file("scores.txt", ios::app); // append mode
            if (file.is_open()) {
                file << score_str << endl;
                file.close();
                mvprintw(1, 1, "File write operation performed successfully!");
                refresh();
            } else {
                mvprintw(1, 1, "Unable to open file for writing");
                refresh();
            }
            */
            /*
            ifstream obj("scores.txt");
            if (obj.is_open()) {
                int row = 1;
                char line[100]; 
                while (obj.getline(line, 100)) {
                    mvprintw(row++, 1, "%s", line);
                }
                obj.close();
            } else {
                mvprintw(1, 1, "Unable to open file for reading");
                refresh();
            }
            */
        }

    } while(sel != 2);

    endwin();

    return 0;
}
    