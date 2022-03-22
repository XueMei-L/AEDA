#pragma once //_GridWithPeriodicBorder_

#ifndef _GridWithPeriodicBorder_
#define _GridWithPeriodicBorder_
#include "grid.h"

class GridWithPeriodicBorder: public Grid
{
    public:
        GridWithPeriodicBorder();
        GridWithPeriodicBorder(int, int);
        ~GridWithPeriodicBorder() override;

        void insertCellStatus();    // poner celulas vivas
        
        void nextGeneration();      // actualizar los estados

        Cell& getCell(int, int) override;
        const Cell& getCell(int, int) const override;
        std::vector<std::vector<Cell*>*> getMalla() const { return _mallaFrontera; }
        
        void contar(int, int);
    
    private:
        // std::vector<std::vector<Cell*>*> _malla;
        int _rows, _cols;
        std::vector<std::vector<Cell*>*> _mallaFrontera;
        int _neighborsHorizotalVertical;
        int _neighborsDiagonalPriSec;
};

#endif //_GridWithPeriodicBorder_