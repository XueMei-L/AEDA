#pragma once  // _StateDead_

#ifndef _StateDead_
#define _StateDead_
#include "state.hpp"

class StateDead: public State
{
    public:
        StateDead();
        ~StateDead() override;
        int neighbors(const Grid&, int, int)override;
        State* nextState() override;
        char getState() override;
    private:
        int _neighbors;
};

#endif //_StateDead_