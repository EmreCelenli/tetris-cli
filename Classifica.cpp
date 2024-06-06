#include "Classifica.hpp"


Classifica::Classifica(WINDOW *win){
    read_classifica();
    this->win = win;
}
    

void Classifica::update_classifica(int score){
    int i = 0;
    
    while (i < 10 && scores[i] >= score) {
        i++;
    }
    
    if(i < 9){
        for (int j = 9; j > i; j--){
            scores[j] = scores[j - 1];
        }
        scores[i] = score;
    }  
    write_classifica();
}



void Classifica::display_classifica(){
    read_classifica();
    mvwprintw(win, 3, 3, "Scores:");
    for (int i = 0; i < 10; i++) {
        mvwprintw(win, 4 + i, 3, "%d. %d", i + 1, scores[i]);
    }
    wrefresh(win);
    wgetch(win);
}

void Classifica:: write_classifica(){
    ofstream file("scores.txt", ios::out); // out mode
    for(int i = 0; i < 10; i++){
        char score_str[100];
        sprintf(score_str, "%d", scores[i]);
            if (file.is_open()) {
                file << scores[i] << endl;  
            } 
    }  
    file.close(); 
}

void Classifica:: read_classifica(){
    ifstream obj("scores.txt");
        if (obj.is_open()) {
            char line[100]; 
            for(int i = 0; i < 10; i++){
                if(obj.getline(line, 100)){
                    scores[i] = stoi(line);
                }    
            }
            obj.close();
        }
}

void Classifica:: initialize_classifica(){
    ofstream file("scores.txt");
    for(int i = 0; i < 10; i++){
        file << "0" << endl;
    }
    file.close();
}

bool Classifica::fileExists(){
    ifstream file("scores.txt");
    return file.is_open();
}