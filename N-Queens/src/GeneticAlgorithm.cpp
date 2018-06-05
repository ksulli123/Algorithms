#include "GeneticAlgorithm.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

GeneticAlgorithm::GeneticAlgorithm(int queens)      //Constructor
{
    size = queens;
    maxFitness=FitnessFN(size);
    Eval();                                         //Calls evaluate function which reproduces, crossovers and mutates the population to create the children
}

GeneticAlgorithm::~GeneticAlgorithm()
{
    //dtor
}


void GeneticAlgorithm::initialize(){                //Initializes the population. Several parents are created
    srand(time(0));
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            int val = rand() % size;
            population[i][j] = val;
        }
    }
}

int GeneticAlgorithm::FitnessFN(int queens){
    int n = queens - 1;                   //The maximum number of attacks for 8 size board is 7+6+...+1
    int weight = (n*(n+1))/2;               //Using n(n+1)/2
    return weight;                      //returns maximum weight/heuristic
}

void GeneticAlgorithm::mutate(int x){                   //Applying random mutation to
    if((rand()%100)<=(mutProb*100)){
        int offspring = rand()%2;
        if(offspring==0){
                children[x][rand()%size] = rand()%size;
        }else{
            children[x+1][rand()%size] = rand()%size;
        }
    }
}

void GeneticAlgorithm::reproduce(){

    for(int i = 0;i<size;i+=2){                     //add two to i because we look at two parents i & i + 1
        int parent1 = probDist[rand()%length];
        int parent2 = probDist[rand()%length];
        int entry = rand()%size;                // select random entry for split
        for(int gene=0;gene<entry;gene++){          //children get dna of parents upto entry/Crossover.

            children[i][gene] = population[parent1][gene];
            children[i+1][gene] = population[parent2][gene];

        }
        for(int gene=entry;gene<size;gene++){                 //splicing the dna. e.g. child i gets parent1's dna upto entry and parent2's dna from entry

            children[i][gene] = population[parent2][gene];
            children[i+1][gene] = population[parent1][gene];


        }

        mutate(i);

    }
}

int GeneticAlgorithm::randomize(int num){           //returns rand%num but issue with seed was occurring so this function is not used for now.
    if(num==0) return 0;
    else return rand() % num;
}

int GeneticAlgorithm::getFitness(int queens[]){
    int fitness = FitnessFN(size);

    for (int i = 0; i < size; i++){
        for(int j = i+1;j<size;j++){
            if(queens[i]==queens[j]){fitness-=1;}   //find if another queen is on same column
            if(abs(i-j)==abs(queens[i]-queens[j])){fitness-=1;}   //find if another queen is on a diagonal location
        }
    }
    return fitness;                 //return maximum fitness - cost
}

void GeneticAlgorithm::Eval(){

    mutProb = 0.2;                      //Set mutation probability to 10%
    found = false;                      //Bool for whether the solution is found;
    population = new int* [size];
    for(int i = 0;i < size;i++) population[i] = new int[size];

    children = new int* [size];
    for(int i = 0;i < size;i++) children[i] = new int[size];


    initialize();
    probDist = new int[maxFitness*size];
    length=0;                       //length of probability distribution array;
    while(found==false){
        for(int i = 0;i<length;i++){        //reinitialize probability distribution for next offspring
            probDist[i] = (int)NULL;
        }
        length=0;

        getProbDist();
        reproduce();
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                    population[i][j]=children[i][j];
            }
        }


        for(int i = 0; i < size; i++){
            if(getFitness(children[i])==maxFitness){       //if the fitness of the child in the child population = 0 then the
                cout << "Solution found" << endl;
                printQueens(children[i]);
                found=true;
            }
        }

    }
    cout << "Program ended" << endl;
}

void GeneticAlgorithm::getProbDist(){           //returns the probability distribution
    for(int i=0;i<size;i++){
        //printQueens(population[i]);
        int x = getFitness(population[i]);
        //cout << x << endl;
        for(int j = 0; j < x; j++){
            probDist[length]=i;
            length++;
        }
    }
}

void GeneticAlgorithm::printQueens(int queens[]){

    for (int i=0;i<size;i++){
            for (int j = 0; j < size;j++){
                if(queens[i]==j){
                    cout << "Q ";
                } else {
                    cout << "O ";
                }

            }
            cout << endl;
        //cout << "Queen " << i  << " row: " << queens[i].getRow() << " col: " << queens[i].getCol() << endl;
    }
    cout << "- - - -" << endl;
}
