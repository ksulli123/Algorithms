#include "Queens.h"

Queens::Queens(){

}

Queens::Queens(int row, int col)
{
    this->row = row;
    this->col = col;
}

Queens::~Queens()
{
    //dtor
}

void Queens::setLoc(int row, int col){
    this->row = row;
    this->col = col;
}

int Queens::getRow(){
    return this->row;
}

int Queens::getCol(){
    return this->col;
}

void Queens::setThreat(bool attackable){
    threat=attackable;
}

bool Queens::getThreat(){
    return threat;
}


