#include "grid.hpp"
#include "cell.hpp"


// Constructor
Grid::Grid(int rows, int cols): _N(rows), _M(cols) {
    
    //Redimensionar la malla (+2 para los bordes)
    std::vector<Cell*> *aux;

    for(int i = 0; i < rows+2; i++) {

        aux = new std::vector<Cell*>;

        for (int j = 0; j < cols+2; j++) {
            aux->push_back(new Cell(0, std::make_pair(i, j)));
        }
        _malla.push_back(aux);
    }
    // _malla = _mallaNew;
}

// Desctructor
Grid::~Grid(){}

// const Cell& Grid::getCell(int, int) {
    
// }

// ask to user to cell state
void Grid::insertCellStatus() {
    int stateAliveI;
    int stateAliveJ;
    int stopInsert = 1;
    std::cout << "\n------------------Insert cell state process-----------------\n"
              << "Introduce the cell with state ALIVE:" << std::endl;
              
    // Range is from 0 to N+1, beacause it is starts from 0 not 1
    std::cout << "the rango is: rows [ 0 - " << _N+1 << " ] cols [ 0 - " << _M+1 << "]" <<std::endl;

    //Let user change state
    while(stopInsert == 1) {
        std::cout << "pos: ";
        std::cin >> stateAliveI >> stateAliveJ;

        //Check posicion is in the range
        if((stateAliveI < 0 || stateAliveI > _N+1) || stateAliveJ < 0 || stateAliveJ > _M+1){
            std::cout << "Posicion error\n"
                      << "Please, introduce a correct posicion.\n";
        }else{
            std::cout << "pos[" << stateAliveI << "][" << stateAliveJ << "] = 1" << std::endl;
            _malla[stateAliveI]->data()[stateAliveJ]->setState(1);
            std::cout << "Do u want insert more posicion withe state ALIVE (yes, write 1 / no, write 0):";
            std::cin >> stopInsert;
        }
    }
}

void Grid::nextGeneration() {
    // Counter neighbors
    for(int i = 1; i < _N+1; i++) {
        for(int j = 1; j < _M+1; j++) {
            getMalla()[i] ->data()[j]->neighbors(*this);
        }
    }

    // Update Status
    std::cout << "update process" << std::endl;

    for(int i = 1; i < _N+1; i++) {
        for(int j = 1; j < _M+1; j++) {
            getMalla()[i]->data()[j]->updateState();
            // _mallaNew[i]->data()[j]->updateState();
        }
    }
}


// Show the grid
void Grid::print(std::ostream& os) {
    // std::cout << "----------print function---------------\n";
    for(int i = 1; i <= _N; i++) {
        for(int j = 1; j <= _M; j++) {
            //std::cout << "x ";
            std::cout << "[" << i << "][" << j << "]";
            _malla[i]->data()[j]->print(os);
        }
        os << "\n";
    }
}