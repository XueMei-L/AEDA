#include "stateDead.hpp"


StateDead::StateDead(){}

StateDead::~StateDead(){}


int StateDead::neighbors(const Grid& malla, int i, int j);
{   
    
}


char StateDead::getState() const
{
    return 'D';
}


State* StateDead::nextState()
{

    if(_neighbors >= 2) {
    return new StateDead();
        state = "huevo";
    }else{
        state = "dead";
    }

    return state;
}


