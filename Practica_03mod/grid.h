#pragma once //_GRID_

#ifndef _GRID_
#define _GRID_

#include "cell.h"
#include <vector>

//Para usar la clase, directamente hace:
//class B;

class Grid
{
private:
    /* data */
    int _N; // Numero de filas
    int _M; // Numero de columas
    std::vector<std::vector<Cell*>*> _malla;

public:

    Grid();
    Grid(int, int);             //iniciar todos muertos
    virtual ~Grid();

    void insertCellStatus();    // poner celulas vivas
    
    virtual Cell& getCell(int, int) = 0;
    virtual const Cell& getCell(int, int) const = 0;
    
    void nextGeneration();      // actualizar celulas
    
    void print(std::ostream& os = std::cout);

    std::vector<std::vector<Cell*>*> getMalla() const { return _malla; }
};

#endif //_Grid_