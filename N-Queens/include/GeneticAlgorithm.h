#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H


class GeneticAlgorithm
{
    public:
        GeneticAlgorithm(int size);
        virtual ~GeneticAlgorithm();
        void initialize();
        int FitnessFN(int queens);
        int getFitness(int queens[]);
        void mutate(int x);
        void reproduce();
        int randomize(int num);
        void Eval();
        void getProbDist();
        void printQueens(int queens[]);
    protected:

    private:
        int size;
        int** population;
        int** children;
        float mutProb;
        bool found;
        int* probDist;
        int maxFitness;
        int length;
};

#endif // GENETICALGORITHM_H
