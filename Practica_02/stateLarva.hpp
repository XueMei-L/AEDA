#pragma once  // _StateLarva_

#ifndef _StateLarva_
#define _StateLarva_

class StateLarva: public State
{
    public:
        StateLarva();
        ~StateLarva();
        int neighbors(const, int, int);
        State* nextState();
        char getState();
}

#endif //_StateLarva_