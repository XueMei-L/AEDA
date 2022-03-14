/************************************************************************** 
 * AUTHOR: XueMei Lin
 * DATE: 08/03/2022
 * EMAIL: alu0101225845@ull.edu.es
 * GITHUB: XueMei-L
 * UNIVERSITY: Universidad de La Laguna
 * SUBJECT: Algoritmos y estructruas de datos avanzadas
 * PRACTICENUM: 1
 * VERSION: 1.0
 * TITLE: El juego de la vida
 * LENGUAJE: C++
 * TOOLS: Visual Studio Code && iaaS
 * MAKEFILE: make (compile files) 
 *           make clean (Delete files other than the source code)
 * DESCRIPTION: https://es.m.wikipedia.org/wiki/Juego_de_la_vida
 ***************************************************************************/

/* INCLUDES */
#include "cell.hpp"
#include "grid.hpp"

// Constructor
Cell::Cell(int state, std::pair<int, int> pos){
    _state = state;
    _pos.first = pos.first;
    _pos.second = pos.second;
    _numNeighbors = 0;
};

// Desctructor
Cell::~Cell(){};

std::ostream& operator<<(std::ostream& os, const Cell *cell) {
    
    if(cell-> getState())
        os << "X";
    else
        os << " ";
    return os;

}

std::ostream& Cell::print(std::ostream& os) {
    if(getState()) os << "X";
    else os << " ";

    return os;
}

//Count nsetState(int state)um of Neighbors
int Cell::neighbors(const Grid& malla) {
    _numNeighbors = 0;

    //Save actually posicion
    int posActualI = _pos.first;
    int posActualJ = _pos.second;
    
    // std::cout << "estoy en la pos[" << posActualI << "][" << posActualJ << "] \n";
    std::cout << "posActual[" << posActualI << "][" << posActualJ << "], ";
    std::cout << "neighbors=" << _numNeighbors << std::endl;

        //Modificacion
        if(i != posActualI || j != posActualJ) {
            if(malla.getMalla()[i]->data()[j]->getState() == 1){
                if((i == posActualI-1 && j == posActualJ) || (i == posActualI+1 && j == posActualJ) || (i == posActualI && j == posActualJ-1) || (i == posActualI && j == posActualJ+1)) {
                        _numNeighbors += 2;
                }else{
                        _numNeighbors++;
                }
            }
        }

    // std::cout << "posActual[" << posActualI << "][" << posActualJ << "], ";
    // std::cout << "neighbors=" << _numNeighbors << std::endl;
 
    return _numNeighbors;
}

//updateState
void Cell::updateState() {

    // std::cout << "Numero de vecinos" << _numNeighbors;
    int nextState = 0;
    // std::cout << "\nnumNeighbors is =" << _numNeighbors;
    // If it is a 0 stat   and number of neighbors is equal to 3, state = 1
    if(getState() == 0 && _numNeighbors == 4) { nextState = 1; }
    
    // If it is a 1 state and number of neighbors is equal to 2 or 3, state = 1
    else if(getState() == 1 && (_numNeighbors == 3 || _numNeighbors == 4)) { nextState = 1; }
    
    // In other case, the state is 0
    else { nextState = 0; }

    // std::cout << "\nnext state is:" << nextState;
    setState(nextState);
}