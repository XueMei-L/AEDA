#pragma once  // _StatePupa_

#ifndef _StatePupa_
#define _StatePupa_

class StatePupa: public State
{
    public:
        StatePupa();
        ~StatePupa();
        int neighbors(const, int, int);
        State* nextState();
        char getState();
}

#endif //_StatePupa_