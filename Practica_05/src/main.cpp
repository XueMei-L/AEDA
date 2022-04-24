// includes
#include <iostream>

#include "../include/ordenacion.h"
#include "../include/ordSeleccion.h"

// tipo generico
using Key = int;

// programa principal
int main(int argc, char *argv[]) {
    std::cout << "----------------Bienvenido al programa de ordenacion---------------" << std::endl;
    
    // Preguntar el tañamo de la secuencia
    int nSeq;
    std::cout << ">>> Introduzca el tamaño de la secuencia:";
    std::cin >> nSeq;

    Ordenacion<Key>* ptr_ord;
    ptr_ord = new Seleccion<Key>();

    // Preguntar que tipo de algoritmo de ordenacion
    // int selectAlgorithm;
    // bool stop = false;
    // while (!stop)
    // {
    //     std::cout << ">>> Elijas un algoritmo de ordenacion:" 
    //             << "\n1. Seleccion"
    //             << "\n2. QuickSort"
    //             << "\n3. ShellSort"
    //             << "\n3. HeapSort"
    //             << "\n3. RadixSort"
    //             << "\nTu seleccion es:"; 
    //     std::cin >> selectAlgorithm;
    //     std::cout << "Your seleccion is:" << selectAlgorithm;
    //     stop = true;
    // }
    // switch (selectAlgorithm)
    // {
    // case 1:
    //     ptr_ord = new Seleccion<Key>();
    //     // ptr_fd = new fdModule<Key>(nTable);
    //     break;
    // case 2:
    //     break;
    // case 3:
    //     break;
    // default:
    //     std::cout << "No es una opción valida, vuelva a ejecutar el programa." << std::endl;
    //     break;
    // }

    std::cout << "\n----------------Terminando el programa---------------" << std::endl;
    return 0;
}