#include "Tetramino.hpp"

Tetramino::Tetramino(){
    srand(time(0));
    this->id = rand() % 7;

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
        case KEY_UP:
            for(int i = 0; i < 4; i++)
                block[i].y--;
            break;
        default:
            break;
    }
}

void Tetramino::convertCoordinates(point relativeCoordinates[], point gridCoordinates[]){
    for(int i = 0; i < 4; i++){
        gridCoordinates[i].y = relativeCoordinates[i].y + block[0].y;
        gridCoordinates[i].x = relativeCoordinates[i].x + block[0].x;
    }
}

int Tetramino::getID(){
    return this->id;
}

void Tetramino::rotate(bool clockwise){
    if(this->id != 1){
        point relativeCoordinates[4];
        for(int i = 0; i < 4; i++){
            relativeCoordinates[i].y = block[i].y - block[0].y;
            relativeCoordinates[i].x = block[i].x - block[0].x;
        }

        int prev_x;

        if(!clockwise){
            for(int i = 0; i < 4; i++){
                prev_x = relativeCoordinates[i].x;
                relativeCoordinates[i].x = relativeCoordinates[i].y;
                relativeCoordinates[i].y = -prev_x;
            }
        }
        else {
            for(int j = 0; j < 3; j++){
                for(int i = 0; i < 4; i++){
                    prev_x = relativeCoordinates[i].x;
                    relativeCoordinates[i].x = relativeCoordinates[i].y;
                    relativeCoordinates[i].y = -prev_x;
                }            
            }

        }       

        point gridCoordinates[4];
        convertCoordinates(relativeCoordinates, gridCoordinates);
        insert(gridCoordinates); 
    }
}

void Tetramino::insert(point gridCoordinates[]){
    for(int i = 0; i < 4; i++)
        block[i] = gridCoordinates[i];
}

int Tetramino::isOut(){
    int isOut = 0;
    for(int i = 0; i < 4; i++){
        if(block[i].x > 9)
            isOut = 1;
        else if(block[i].x < 0)
            isOut = -1;
    }

    return isOut;
}