#pragma once  // _StateEgg_

#ifndef _StateEgg_
#define _StateEgg_

class StateEgg: public State
{
    public:
        StateEgg();
        ~StateEgg();
        int neighbors(const, int, int);
        State* nextState();
        char getState();
}

#endif //_StateEgg_