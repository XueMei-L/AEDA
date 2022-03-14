#pragma once //_CELL_

#ifndef _CELL_
#define _CELL_
#include <iostream>
// Para que la clase Cell puede usar objetos de Grid

enum Status { dead , alive };

class Grid;

class Cell
{
    public:
        Cell(int, std::pair<int, int>);
        ~Cell();
        
        //Getter of state
        int getState() const 
        { return _state; }

        //Setter of state
        int setState(int state)
        { return _state = state; }

        //Update state
        void updateState();

        //Count Neighbors
        int neighbors(const Grid&);

        //Overload stream operator
        friend std::ostream& operator<<(std::ostream&, const Cell&);
        std::ostream& print(std::ostream&);
        
    private:
        /* data */
        std::pair<int, int> _pos;
        int _state;
        int _numNeighbors;

};

#endif //_CELL_
