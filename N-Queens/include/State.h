#ifndef STATE_H
#define STATE_H
#include <vector>
#include "Queens.h"
using namespace std;

class State
{
    public:
        State();
        void createBoard(int size);
        State(int size,vector<Queens>& queens);
        virtual ~State();
        void calcHeuristic();
        int getHeuristic();
        State getNeighbour();
        vector<Queens> getQueens();
        void printQueens();
        void reinit();



    protected:
        vector<Queens> queens;
    private:
        int size;
        int heuristic;
};

#endif // STATE_H
