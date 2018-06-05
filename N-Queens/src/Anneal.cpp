#include "Anneal.h"
#include "Queens.h"
#include "State.h"
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

Anneal::Anneal(int numQueens, double temperature)
{
    this->numQueens=numQueens;
    this->temperature=temperature;
    count=0;
    current.createBoard(numQueens);             //Initialize board
    State result = AnnealAlgorithm();


}

Anneal::~Anneal()
{
    //dtor
}

State Anneal::AnnealAlgorithm(){
    double probability;
    double chance;
    while(current.getHeuristic()!=0 && temperature>0){      //If heuristic is greater than 0 and temperature not 0 then repeat. sometimes temperature =0 before solution is found
        State neighbour = current.getNeighbour();
        count++;
        if(neighbour.getHeuristic()==0){
            cout << "Solution found" << endl;
            neighbour.printQueens();
            return neighbour;
        }
        if (neighbour.getHeuristic() < current.getHeuristic()){        //if neighbour's h is lower than current, set current to h
            current = neighbour;
        }else{
            probability = exp((current.getHeuristic()-neighbour.getHeuristic())/temperature);       //determine probability to accept move
            chance = rand();
            if(chance<=probability){
                current = neighbour;
            }
        }
        temperature-=0.00001;
    }
    return current;
}
