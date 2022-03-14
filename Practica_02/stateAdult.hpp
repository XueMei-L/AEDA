#pragma once  // _StateAdult_

#ifndef _StateAdult_
#define _StateAdult_

class StateAdult: public State
{
    public:
        StateAdult();
        ~StateAdult();
        int neighbors(const, int, int);
        State* nextState();
        char getState();
}

#endif //_StateAdult_