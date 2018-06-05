#include "State.h"
#include <vector>
#include "Queens.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

State::State(){
    //cstr
}

void State::createBoard(int size)
{

    this->size=size;
    for (int i=0;i<size;i++){        //Put queens in random columns in next row per queen
        int col = rand() % size;
        queens.push_back(Queens(i,col));
    }
    calcHeuristic();
}

State::State(int size,vector<Queens>& queens){  //create state object from passing in a vector of queens and the size of the vector
    this->size = size;
    this->queens=queens;
    heuristic = 0;
}

State::~State()
{
    //dtor
}

void State::calcHeuristic(){
    heuristic=0;
    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            if(queens[i].getRow()==queens[j].getRow()           //Check if queen i is on the same row as queen j
               || queens[i].getCol()==queens[j].getCol()        //Check if queen i is on the same column as queen j
               || abs(queens[i].getRow()-queens[j].getRow())==abs(queens[i].getCol()-queens[j].getCol())){      //Check diagonal
                    //cout << i << j << endl;
                    heuristic++;
                    queens[i].setThreat(true);
                    queens[j].setThreat(true);
                }
        }
    }

}

int State::getHeuristic(){
    calcHeuristic();
    return heuristic;
}

State State::getNeighbour(){
    calcHeuristic();
    vector<Queens> nextState = queens;
    int randQueen = rand() % size;
    while (&queens[randQueen].getThreat==false){        //Only randomly select a queen that is threatened otherwise randomly pick again until true
        randQueen = rand() % size;
        cout << randQueen << endl;
    }

    int col = rand() % size;
    while(col==nextState[randQueen].getCol()){      //select a random queen and move in a random direction
        col=rand()%size;
    }

    nextState[randQueen].setLoc(randQueen,col);
    State neighbour(size, nextState);
    return neighbour;
}

void State::printQueens(){
    for (int i=0;i<queens.size();i++){
            for (int j = 0; j < queens.size();j++){
                if(queens[i].getCol()==j){
                    cout << "Q ";
                } else {
                    cout << "O ";
                }

            }
            cout << endl;
        //cout << "Queen " << i  << " row: " << queens[i].getRow() << " col: " << queens[i].getCol() << endl;
    }
}

vector<Queens> State::getQueens(){return queens;}

void State::reinit(){           //This is to clear the vector of queens in the state for random restart
    queens.clear();
}
