#pragma once //_GridWithNoBorder_

#ifndef _GridWithNoBorder_
#define _GridWithNoBorder_

#include "grid.h"

class GridWithNoBorder: public Grid
{
    public:
        GridWithNoBorder();
        GridWithNoBorder(int, int);
        ~GridWithNoBorder();

        void insertCellStatus();    // poner celulas vivas
        
        void nextGeneration();

        Cell& getCell(int, int);
        const Cell& getCell(int, int) const;
        std::vector<std::vector<Cell*>*> getMalla() const { return _mallaFrontera1; }
    
    private:
        // std::vector<std::vector<Cell*>*> _malla;
        int _rows, _cols;
        std::vector<std::vector<Cell*>*> _mallaFrontera1;
        
};


#endif _GridWithNoBorder_