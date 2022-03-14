#pragma once  // _StateDead_

#ifndef _StateDead_
#define _StateDead_

class StateDead: public State
{
    public:
        StateDead();
        ~StateDead();
        int neighbors(const, int, int);
        State* nextState();
        char getState();
}

#endif //_StateDead_