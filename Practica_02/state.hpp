#pragma once  // _State_

#ifndef _State_
#define _State_


class State
{
    private:
        /* data */
    public:
        State(/* args */);
        virtual ~State();
        virtual int neighbors(const, int, int) = 0;
        virtual State* nextState() = 0;
        virtual char getState() = 0;
};


State::State(/* args */){}

State::~State(){}



class StateEgg: public State
{
    public:
        int neighbors(const, int, int);
        State* nextState();
        char getState();
}

class StateLarva: public State
{
    public:
        int neighbors(const, int, int);
        State* nextState();
        char getState();

}

class StatePupa: public State
{
    public:
        int neighbors(const, int, int);
        State* nextState();
        char getState();
}

class StateAdult: public State
{
    public:
        int neighbors(const, int, int);
        State* nextState();
        char getState();
}

class StateDead: public State
{
    public:
        int neighbors(const, int, int);
        State* nextState();
        char getState();
}

#endif //_State_