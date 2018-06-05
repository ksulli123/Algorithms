#ifndef ANNEAL_H
#define ANNEAL_H
#include "Queens.h"
#include <vector>
#include "State.h"
using namespace std;

class Anneal
{
    public:
        Anneal(int numQueens, double temperature);
        virtual ~Anneal();
        State AnnealAlgorithm();

        void getNeighbour();
    private:
        double temperature;
        int numQueens;
        State current;
        int count;
};

#endif // ANNEAL_H
