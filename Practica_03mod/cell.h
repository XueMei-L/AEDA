#pragma once //_CELL_

#ifndef _CELL_
#define _CELL_
#include <iostream>
#include "state.hpp"

class Grid;

class Cell
{
    public:
        Cell();
        Cell(State*, std::pair<int, int>);
        ~Cell();
        
        //Getter of state
        char getState() const 
        { return _state; }

        //Setter of state
        char setState(char state)
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
        char _state;
        int _numNeighbors;

};

#endif //_CELL_
