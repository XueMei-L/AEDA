#pragma once  // _State_

#ifndef _State_
#define _State_

#include "grid.hpp"

class State
{
    private:
        /* data */
        // int _neighbors
    public:
        State(/* args */);
        virtual ~State();
        virtual int neighbors(const Grid&, int, int) = 0;
        virtual State* nextState() = 0;
        virtual char getState() = 0;
};


State::State(/* args */){}

State::~State(){}

#endif //_State_