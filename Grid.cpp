#include "Grid.hpp"
#include "Scores.hpp"

Grid::Grid(WINDOW * win) : block(){
    this->win = win;
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 10; j++)
            grid[i][j] = false;
    }
}

void Grid::addBlock(){
    point blockCoordinates[4];
    block.getCoordinates(blockCoordinates);

    for(int i = 0; i < 4; i++)
        grid[blockCoordinates[i].y][blockCoordinates[i].x] = true;
}

void Grid::displayGrid(){
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j += 2){
            if(grid[i][j/2])
                mvwprintw(win, i, j, "[]");
            else 
                mvwprintw(win, i, j, " %c", 46);
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

    bool blocksCondition, borderCondition;    
    bool isFree = true;

    for(int i = 0; i < 4; i++){
        switch(direction){
            case KEY_DOWN:
                blocksCondition = grid[blockCoordinates[i].y + 1][blockCoordinates[i].x];
                borderCondition = blockCoordinates[i].y + 1 > 19;
                break;
            case KEY_RIGHT:
                blocksCondition = grid[blockCoordinates[i].y][blockCoordinates[i].x + 1];
                borderCondition = blockCoordinates[i].x + 1 > 9;
                break;
            case KEY_LEFT:
                blocksCondition = grid[blockCoordinates[i].y][blockCoordinates[i].x - 1];
                borderCondition = blockCoordinates[i].x - 1 < 0;
                break;
            default:
                break;    
        }

        if(blocksCondition || borderCondition) 
            isFree = false;
    }

    if(!isFree)
        addBlock();

    return isFree;
}

void Grid::moveDirection(int direction){
    if(checkDirection(direction))
        block.move(direction);    
    addBlock();
    displayGrid();
}

void Grid::moveDownDelayed(int delay = 10){
    halfdelay(delay);
    int command;

    while(checkDirection(KEY_DOWN)){
        command = wgetch(win);
        if(command != ERR){ 
            switch(command){
                case 97: 
                    rotation(false);
                    break;
                case 100:
                    rotation(true);
                    break;
                default:
                    moveDirection(command);
                    break;
            }
                
            wgetch(win);
        }
        moveDirection(KEY_DOWN);
    }
}

int Grid::game(WINDOW * win){
    Score score;
    bool startOccupied = false;
    while(!startOccupied){
        score.display_score(win);
        addBlock();
        moveDownDelayed();
        int cleared_lines = removeAllLines();
        score.update_score(cleared_lines);
        score.display_score(win);
        Tetramino newblock;
        block = newblock;

        startOccupied = checkBlockArea();        
    }
    cbreak();
    return score.get_score();
}


int Grid::removeAllLines(){
    int removedLines = 0;
    for(int i = 0; i < 20; i++){
        if(checkCompleted(i)){
            for(int j = 0; j < 10; j++){
                grid[i][j] = false;
            }  
            moveDownLines(i); 
            removedLines++;         
        }
    }  
    return removedLines;
}

void Grid::moveDownLines(int line){
    for(int i = line; i > 0; i--){
        for(int j = 0; j < 10; j++)
            grid[i][j] = grid[i-1][j];
    }
}

bool Grid::checkCompleted(int line){ // controlla che una riga sia completa
    bool isComplete = true;
    for(int j = 0; j < 10; j++){
        if(!grid[line][j])
            isComplete = false;
    }

    return isComplete;
}


bool Grid::checkBlockArea(){
    point blockCoordinates[4]; 
    block.getCoordinates(blockCoordinates);

    bool isOccupied = false;
    for(int i = 0; i < 4; i++){
        if(grid[blockCoordinates[i].y][blockCoordinates[i].x])
            isOccupied = true;
    }

    return isOccupied;
}

void Grid::rotation(bool clockwise){ // 1 vuol dire clockwise 0 vuol dire counterclockwise
    if(block.getID() != 1){
        point blockCoordinates[4];
        block.getCoordinates(blockCoordinates);
        removeBlock();
        block.rotate(clockwise);
        
        while(block.isOut() == -1)
            block.move(KEY_RIGHT);
        while(block.isOut() == 1)
            block.move(KEY_LEFT);
        while(block.isOut() == 2)
            block.move(KEY_DOWN);
        while(checkBlockArea())
            block.move(KEY_UP);

        addBlock();
    }    
}
