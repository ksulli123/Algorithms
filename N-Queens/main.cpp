#include <iostream>
#include "HillClimbing.h"
#include "Anneal.h"
#include "GeneticAlgorithm.h"
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <chrono>

using namespace std;

int main()
{


    int numOfQueens;
    char input;
    srand(time(NULL));
    cout << "Please input the number of queens you want." << endl;
    cin >> numOfQueens;

    cout << "Please type in the algorithm you'd like" << endl;
    cout << "h --- Hill Climbing Algorithm" << endl;
    cout << "r -- Random Restart Hill Climbing Algorithm" << endl;
    cout << "s -- Simulated Annealing Algorithm" << endl;
    cout << "g -- Genetic Algorithm" << endl;

    cin >> input;

    clock_t start, stop;
    start = clock();

    if(input=='h'){                                 //Check for input to determine what algorithm to use
        HillClimbing HC(numOfQueens);
    }else if(input=='r'){
        HillClimbing RSHC(numOfQueens, true);
    }else if(input=='s'){
        Anneal AN(numOfQueens, 35);
    }else if(input=='g'){
            GeneticAlgorithm GA(numOfQueens);
    }else{
        cout << "No algorithm found, please try again." << endl;
    }

    stop = clock();

    cout << "Time Elapsed: " << (double)(stop-start)/CLOCKS_PER_SEC << endl;        //Display time elapsed from beginning of search to end

    //cout << "Time Elapsed: " << ((double)(finish - start)) << endl;
    std::getchar();         //This is for the executable which closes immediately upon completing function otherwise
    system("pause");
}
