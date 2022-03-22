#include "stateDead.h"
#include "stateAlive.h"

StateDead::StateDead(){}

StateDead::~StateDead(){}


int StateDead::neighbors(const Grid& malla, int i, int j)
{
    _neighbors = 0;

    int posActualI = i;
    int posActualJ = j;

    for(int i = posActualI-1; i <= posActualI + 1; i++) {
        for(int i = posActualJ -1; j <= posActualJ +1; j++) {
            if(i != posActualI || j != posActualJ) {
                if(malla.getMalla()[i]->data()[j]->getState() == "D") {
                    _neighbors++;
                }
            }
        }
    }

    return _neighbors;
}


char StateDead::getState()
{
    return 'D';
}


State* StateDead::nextState()
{
    if(_neighbors == 3) {
        return new StateAlive();
    }

    return new StateDead();
}


