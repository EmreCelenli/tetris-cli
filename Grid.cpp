#include "Grid.hpp"

Grid::Grid(WINDOW * win) : block(){
    this->win = win;
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 10; j++)
            grid[i][j] = false;
    }

    addBlock();
}

void Grid::addBlock(){
    point blockCoordinates[4];
    block.getCoordinates(blockCoordinates);

    for(int i = 0; i < 4; i++)
        grid[blockCoordinates[i].y][blockCoordinates[i].x] = true;
}

void Grid::displayGrid(){
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 10; j++){
            if(grid[i][j])
                mvwaddch(win, i, j, '*');
            else 
                mvwaddch(win, i, j, ' ');
        }
    }
    wrefresh(win);
}

void Grid::removeBlock(){
    point blockCoordinates[4];
    block.getCoordinates(blockCoordinates);

    for(int i = 0; i < 4; i++)
        grid[blockCoordinates[i].y][blockCoordinates[i].x] = false;  
}

bool Grid::checkDirection(int direction){
    point blockCoordinates[4];
    block.getCoordinates(blockCoordinates);

    removeBlock();

    bool condition;    
    bool isFree = true;

    for(int i = 0; i < 4; i++){
        switch(direction){
            case KEY_DOWN:
                condition = grid[blockCoordinates[i].y + 1][blockCoordinates[i].x];
                break;
            case KEY_RIGHT:
                condition = grid[blockCoordinates[i].y][blockCoordinates[i].x + 1];
                break;
            case KEY_LEFT:
                condition = grid[blockCoordinates[i].y][blockCoordinates[i].x - 1];
                break;
            default:
                break;    
        }

        if(condition) 
            isFree = false;
    }

    return isFree;
}

void Grid::moveDirection(int direction){
    if(checkDirection(direction))
        block.move(direction);    
    addBlock();
    displayGrid();
}

void Grid::moveDownDelayed(){
    while(1){
        moveDirection(KEY_DOWN);
        sleep(1);
    }
}

