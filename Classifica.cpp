
Classifica::Classifica(WINDOW *win){
    ifstream obj("scores.txt");
        if (obj.is_open()) {
            char line[100]; 
            int i = 0;
            while (obj.getline(line, 100)) {
                scores[i] = atoi(line);
                i++;
            }
            obj.close();
        }
    for (int i = 0; i < 10; i++){
        this->scores[i] = atoi(score_str[i]);
    }
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
}



void Classifica::display_classifica(){
    mvwprintw(win, 3, 3, "Scores:");
    for (int i = 0; i < 10; i++) {
        mvwprintw(win, 4 + i, 3, "%d. %d", i + 1, scores[i]);
    }
    wrefresh(win);
    wgetch(win);
}

void Classifica:: write_classifica(){
    for(int i = 0; i < 10; i++){
        char score_str[100];
        sprintf(score_str, "%d", score);
          ofstream file("scores.txt", ios::app); // append mode
            if (file.is_open()) {
                file << score_str << endl;
                file.close();  
            } 
    }
} 

void Classifica:: read_classifica(){
    for(int i = 0; i < 10; i++){
        scores[i] 
    }
}