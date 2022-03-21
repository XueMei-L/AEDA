#include "grid.hpp"

class GridWithNoBorder: public Grid
{
    private:
        /* data */
    public:
        GridWithNoBorder(/* args */);
        ~GridWithNoBorder();

        void insertCellStatus();    // poner celulas vivas
        
        Cell& getCell(int, int);
        const Cell& getCell(int, int) const;
};

GridWithNoBorder::GridWithNoBorder(/* args */)
{
}

GridWithNoBorder::~GridWithNoBorder()
{
}
