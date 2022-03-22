#pragma once  // _StateAlive_

#ifndef _StateAlive_
#define _StateAlive_
#include "state.hpp"

class StateAlive: public State
{
    public:
        StateAlive();
        ~StateAlive() override;
        int neighbors(const Grid&, int, int) override;
        State* nextState() override;
        char getState() override;
    private:
        int _neighbors;
};

#endif //_StateAlive_