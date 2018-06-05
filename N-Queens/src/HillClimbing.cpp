#include "HillClimbing.h"
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Queens.h"
#include <iostream>
#include "State.h"
using namespace std;

HillClimbing::HillClimbing(int numOfQueens)         //Normal constructor for hill climbing
{
    current.createBoard(numOfQueens);
    cout << current.getHeuristic() << endl;
    getNeighbor();
    printQueens();
}

HillClimbing::HillClimbing(int numOfQueens, bool rand)      //This constructor is for the random restart. If h does not equal 0
{                                                           //Then reinitialize board.
    attempts = 1;
    do{
    current.createBoard(numOfQueens);
    getNeighbor();
    current.reinit();
    }while(h>0);
    cout << "Attempts: " << attempts << endl;
}

HillClimbing::~HillClimbing()
{
    //dtor
}

void HillClimbing::printQueens(){
    vector<Queens> queens = current.getQueens();
    for (int i=0;i<queens.size();i++){
            for (int j = 0; j < queens.size();j++){
                if(queens[i].getCol()==j){              //If the current column is overlapps with a queen column, print Q else print O
                    cout << "Q ";
                } else {
                    cout << "O ";
                }

            }
            cout << endl;
        //cout << "Queen " << i  << " row: " << queens[i].getRow() << " col: " << queens[i].getCol() << endl;
    }
    cout << "- - - -" << endl;      //To separate each instance of a printQueen
}

void HillClimbing::getNeighbor(){
                              //create copy of queens to find neighbor

    for(int count = 0; count < 30;count++){
        State neighbour = current.getNeighbour();
        //cout << neighbour.getHeuristic() << endl;
        if(neighbour.getHeuristic()<current.getHeuristic()){
            current = neighbour;
            current.getHeuristic();
        }
    }


    if(current.getHeuristic()==0){
        cout << "Solution found"<<endl;
        printQueens();

    }else{
        //cout << "Solution not found" << endl;
        attempts++;
    }
    h = current.getHeuristic();
}

void randomRestart(){
    //queens.clear();
}
