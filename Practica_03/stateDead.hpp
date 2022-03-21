#pragma once  // _StateDead_

#ifndef _StateDead_
#define _StateDead_
#include "state.hpp"

class StateDead: public State
{
    public:
        StateDead();
        ~StateDead();
        int neighbors(const Grid&, int, int);
        State* nextState();
        char getState();
    private:
        int _neighbors;
};

#endif //_StateDead_