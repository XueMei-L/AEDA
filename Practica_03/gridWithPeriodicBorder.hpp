#include "grid.hpp"

class GridWithPeriodicBorder: public Grid
{
    private:
        /* data */
    public:
        GridWithPeriodicBorder(/* args */);
        ~GridWithPeriodicBorder();

        void insertCellStatus();    // poner celulas vivas
        
        Cell& getCell(int, int);
        const Cell& getCell(int, int) const;
};

GridWithPeriodicBorder::GridWithPeriodicBorder(/* args */)
{
}

GridWithPeriodicBorder::~GridWithPeriodicBorder()
{
}
