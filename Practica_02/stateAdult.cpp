#include "stateAdult.hpp"


StateAdult::StateAdult(){}

StateAdult::~StateAdult(){}


int StateAdult::neighbors
{
    
}

char StateAdult::getState() const
{
    return Adult:
}


State* StateAdult::nextState()
{
    if(getState() == Adult && _neighbors >= 2) {
        return new StateEgg();
    }else{
        return new StateAdult
    }


}
