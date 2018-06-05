#ifndef QUEENS_H
#define QUEENS_H


class Queens
{
    public:
        Queens();
        Queens(int row, int col);
        virtual ~Queens();
        void setLoc(int row, int col);
        int getRow();
        int getCol();
        void setThreat(bool attackable);
        bool getThreat();
        bool canAttack();

    private:
        int row;
        int col;   //The row and column location of the queen
        bool threat=false;
};

#endif // QUEENS_H
