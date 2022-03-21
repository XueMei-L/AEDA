#include "grid.hpp"

class GridWithOpenBorder: public Grid
{
    private:
        /* data */
    public:
        GridWithOpenBorder(/* args */);
        ~GridWithOpenBorder();

        void insertCellStatus();    // poner celulas vivas
        
        Cell& getCell(int, int);
        const Cell& getCell(int, int) const;
};

GridWithOpenBorder::GridWithOpenBorder(/* args */)
{
}

GridWithOpenBorder::~GridWithOpenBorder()
{
}
