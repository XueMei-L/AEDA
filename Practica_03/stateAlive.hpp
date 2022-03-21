#pragma once  // _StateAlive_

#ifndef _StateAlive_
#define _StateAlive_
#include "state.hpp"

class StateAlive: public State
{
    public:
        StateAlive();
        ~StateAlive();
        int neighbors(const Grid&, int, int);
        State* nextState();
        char getState();
    private:
        int _neighbors;
};

#endif //_StateAlive_