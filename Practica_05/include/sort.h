#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <vector>

#include "./ordenacion.h"
#include "./ordSeleccion.h"
#include "./ordQuickSort.h"
#include "./ordHeapSort.h"

template<class Key>
class Sort
{
    private:
        std::vector<Key>& _seq;
        int _seqSize;
        void copyOrdSeq(std::vector<Key>&);

    public:
        Sort();
        Sort(std::vector<Key>&, int);
        ~Sort();

};

template<class Key>
Sort<Key>::Sort() {}

template<class Key>
Sort<Key>::Sort(std::vector<Key>& seq, int n): _seq(seq), _seqSize(n) {
    // Preguntar que tipo de algoritmo de ordenacion
    int selectAlgorithm;
    int mod = 0;

    bool stop = false;
    while (!stop)
    {
        std::cout << "\n>>> Elijas un algoritmo de ordenacion:" 
                << "\n>>> 1. Seleccion"
                << "\n>>> 2. QuickSort"
                << "\n>>> 3. ShellSort"
                << "\n>>> 4. HeapSort"
                << "\n>>> 5. RadixSort"
                << "\nTu seleccion es:"; 
        std::cin >> selectAlgorithm;
        std::cout << ">>> Has elegido el algoritmo:" << selectAlgorithm;

        // Crear puntero de la clase abstracta Ordenacion
        Ordenacion<Key>* ptr_orden;

        switch (selectAlgorithm)
        {
        case 1:
            std::cout << "\n>>> Sort Process...";
            
            ptr_orden = new Seleccion<Key>();
            ptr_orden->sort(_seq, _seqSize);

            //std::vector<Key> copySequencuence = ptr_orden->sort();
            stop = true;
            break;
        case 2:
            std::cout << "\n>>> Sort Process...";

            ptr_orden = new QuickSort<Key>();
            ptr_orden->sort(_seq, _seqSize);

            stop = true;
            break;

        case 3:
            stop = true;
            break;

        case 4:
            std::cout << "\n>>> Sort Process...";

            ptr_orden = new HeapSort<Key>();
            ptr_orden->sort(_seq, _seqSize);
            
            stop = true;
            break;

        default:
            std::cout << "No es una opción valida, vuelva a ejecutar el programa." << std::endl;
            break;
        }
        // std::string repite;
        // std::cout << "Deseas ordenar con otro algoritmo?(y/n):";
        // std::cin >> repite;
        // if(repite == "y" || repite == "Y") {
        //     stop = false;
        // } else {
        //     stop = true;
        // }
        // if(mod == 0) {
        //     copyOrdSeq(copySequencuence);
        // }
        std::cout << "\nStop while.";
    }
}

template<class Key>
void Sort<Key>::copyOrdSeq(std::vector<Key>& seq) {
    _seq = seq;
}

template<class Key>
Sort<Key>::~Sort() {}

#endif //SORT_H