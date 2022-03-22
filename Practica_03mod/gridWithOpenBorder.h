#pragma once //_GridWithOpenBorder_

#ifndef _GridWithOpenBorder_
#define _GridWithOpenBorder_
#include "grid.h"

class GridWithOpenBorder: public Grid
{
    public:
        GridWithOpenBorder();
        GridWithOpenBorder(int, int);
        ~GridWithOpenBorder() override;

        void insertCellStatus();    // poner celulas vivas
        
        void nextGeneration();      // actualizar los estados

        Cell& getCell(int, int) override;
        const Cell& getCell(int, int) const override;
        std::vector<std::vector<Cell*>*> getMalla() const { return _mallaFrontera; }
    
    private:
        // std::vector<std::vector<Cell*>*> _malla;
        int _rows, _cols;
        std::vector<std::vector<Cell*>*> _mallaFrontera;

};

#endif //_GridWithOpenBorder_
