#ifndef HILLCLIMBING_H
#define HILLCLIMBING_H
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Queens.h"
#include "State.h"
using namespace std;

class HillClimbing
{
    public:
        HillClimbing(int numOfQueens);
        HillClimbing(int numOfQueens, bool rand);
        virtual ~HillClimbing();
        void printQueens();
        int heuristic(vector<Queens>& thisqueens);
        void getNeighbor();
        void randomRestart();   //Essentially function that allows random restart hill climbing
        void init(int numOfQueens);


    private:
        int attempts;
        int size;
        State current;
        int h;

};

#endif // HILLCLIMBING_H
