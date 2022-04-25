// includes
#include <iostream>
#include <vector>

#include "../include/sort.h"

// tipo generico
using Key = int;

// programa principal
int main(int argc, char *argv[]) {
    std::cout << "----------------Bienvenido al programa de ordenacion---------------" << std::endl;
    
    // Preguntar el tañamo de la secuencia
    int nSeq;
    std::cout << ">>> Introduzca el tamaño de la secuencia:";
    std::cin >> nSeq;

    // Introducir los values de la secuencia
    std::vector<Key> sequence;
    Key value;
    for(int i = 0; i < nSeq; i++) {
        bool stop = true;
        while(stop) {
            std::cout << ">>> Introduzca [" << i+1 << "] valor de secuancias:";
            std::cin >> value;
            if( value > 1000 && value < 9999) {
                sequence.push_back(value);
                stop = false;
            } else {
                std::cout << "No es un numero valido, vuelva a introducir.\n";
            }
        }
    }

    // for(auto value: sequence) {
    //     std::cout << "\nValue = " << value;
    // }

    // Crear punteo de la clase Sort
    Sort<Key>* ptr_sort = new Sort<Key>(sequence, nSeq);
    delete ptr_sort;

    std::cout << "\n----------------Terminando el programa---------------" << std::endl;
    return 0;
}