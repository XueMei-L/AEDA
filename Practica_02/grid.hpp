#pragma once //_GRID_

#ifndef _GRID_
#define _GRID_

#include "cell.hpp"
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
    // std::vector<std::vector<Cell*>*> _mallaNew;

public:

    Grid(int, int); //iniciar todos muertos
    ~Grid();

    void nextGeneration();  // actualizar celulas
    const Cell& getCell(int, int) const;
    
    void insertCellStatus();    // poner celulas vivas
    void print(std::ostream& os = std::cout);

    std::vector<std::vector<Cell*>*> getMalla() const { return _malla; }
};

#endif //_Grid_