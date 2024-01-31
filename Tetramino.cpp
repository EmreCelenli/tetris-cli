#include "Tetramino.hpp"

Tetramino::Tetramino(){
    srand(time(0));
    id = rand() % 2;

    for(int i = 0; i < 4; i++)
        block[i] = defaultMatrix[id][i];
}

void Tetramino::getCoordinates(point coordinates[]){
    for(int i = 0; i < 4; i++)
        coordinates[i] = block[i];
}

void Tetramino::move(int direction){
    switch(direction){
        case KEY_DOWN:
            for(int i = 0; i < 4; i++)
                block[i].y++;
            break;
        case KEY_RIGHT:
            for(int i = 0; i < 4; i++)
                block[i].x++;
            break;
        case KEY_LEFT:
            for(int i = 0; i < 4; i++)
                block[i].x--;
            break;
        default:
            break;
    }
}