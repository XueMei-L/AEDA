#include "stateDead.hpp"


StateDead::StateDead(){}

StateDead::~StateDead(){}


int StateDead::neighbors
{
    
}

char StateDead::getState() const
{
    return Dead:
}


State* StateDead::nextState()
{
    static char state = "dead";

    if(getState() == Dead && _neighbors >= 2) {
        state = "huevo";
    }else{
        state = "dead";
    }

    return state;
}


