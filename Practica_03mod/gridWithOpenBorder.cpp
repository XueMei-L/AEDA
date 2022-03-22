#include "gridWithOpenBorder.h"
#include "stateAlive.h"

GridWithOpenBorder::GridWithOpenBorder() {};

GridWithOpenBorder::GridWithOpenBorder(int rows, int cols) :_rows(rows), _cols(cols) {
    
    //Redimensionar la malla (+2 para los bordes)
    std::vector<Cell*> *aux;
    // State* ptr_state = new StateDead();

    for(int i = 0; i < rows+2; i++) {

        aux = new std::vector<Cell*>;

        for (int j = 0; j < cols+2; j++) {
            aux->push_back(new Cell(0, std::make_pair(i, j)));
        }
        _mallaFrontera.push_back(aux);
    }
}

GridWithOpenBorder::~GridWithOpenBorder(){
    // delete ptr_grid;
}

// void GridWithOpenBorder::insertCellStatus();    // poner celulas vivas

Cell& GridWithOpenBorder::getCell(int i, int j) {
    getMalla()[i]->data()[j];
    // ptr_grid->getState();
}

const Cell& GridWithOpenBorder::getCell(int i, int j) const {
    getMalla()[i]->data()[j];
}

void GridWithOpenBorder::insertCellStatus() {
    int stateAliveI;
    int stateAliveJ;
    int stopInsert = 1;
    std::cout << "\n------------------Insert cell state process-----------------\n"
              << "Introduce the cell with state ALIVE:" << std::endl;
              
    // Range is from 0 to N+1, beacause it is starts from 0 not 1
    std::cout << "the rango is: rows [ 0 - " << _rows+1 << " ] cols [ 0 - " << _cols+1 << "]" <<std::endl;

    //Let user change state
    while(stopInsert == 1) {
        std::cout << "pos: ";
        std::cin >> stateAliveI >> stateAliveJ;

        //Check posicion is in the range
        if((stateAliveI < 0 || stateAliveI > _rows+1) || stateAliveJ < 0 || stateAliveJ > _cols+1){
            std::cout << "Posicion error\n"
                      << "Please, introduce a correct posicion.\n";
        }else{
            std::cout << "pos[" << stateAliveI << "][" << stateAliveJ << "] = viva" << std::endl;
            _mallaFrontera[stateAliveI]->data()[stateAliveJ]->setState(new StateAlive());
            std::cout << "Do u want insert more posicion withe state ALIVE (yes, write 1 / no, write 0):";
            std::cin >> stopInsert;
        }
    }

    for(int i = 1; i < _cols-1; i++) {
        // Para primera fila
        getMalla()[0]->data()[i] = getMalla()[_rows]->data()[i];
        // Para la ultima fila
        getMalla()[_rows-1]->data()[i] = getMalla()[1]->data()[i];
    }
    for(int j = 1; j < _rows-1; j++) {
        // Para la columna izq
        getMalla()[j]->data()[0] = getMalla()[_cols-1]->data()[j];
        // Para la columna der
        getMalla()[j]->data()[_cols-1] = getMalla()[_cols-1]->data()[j];
    }
        // Para los esquinas.
        getMalla()[0]->data()[0] = getMalla()[_rows-1]->data()[_cols-1];
        getMalla()[0]->data()[_cols-1] = getMalla()[_rows-1]->data()[1];
        getMalla()[_rows-1]->data()[0] = getMalla()[1]->data()[_cols-1];
        getMalla()[_rows-1]->data()[_cols-1] = getMalla()[1]->data()[1];

}

void GridWithOpenBorder::nextGeneration() {
    // Counter neighbors
    for(int i = 1; i < _rows+1; i++) {
        for(int j = 1; j < _cols+1; j++) {
            getCell(i, j).neighbors(*this);
        }
    }

    // Update Status
    std::cout << "update process" << std::endl;

    for(int i = 1; i < _rows+1; i++) {
        for(int j = 1; j < _cols+1; j++) {
            getCell(i, j).updateState();
        }
    }
}