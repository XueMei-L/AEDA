/********************************************************************
* AUTOR: XueMei Lin
* EMAIL: alu0101225845@ull.edu.es
* UNIVERSIDAD: Universidad de La Laguna
* ASIGNATURA: Algoritmos y estructura de datos avanzadas
* VERSION: 1.0
* PRACTICA: 05
* TITUTLO: Practica 05 Ordenacion
* DESCRIPTION: fichero .h que include sort del algoritmo Heapsort
* COMPILACION: make
*              make clean (para eliminar)
* *****************************************************************/

#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <iostream>
#include <vector>
#include "ordenacion.h"
// #include "MetodoOrdenacion.h"

template<class Key>
class HeapSort: public Ordenacion<Key>
{
    private:
        /* data */
    public:
        HeapSort();
        ~HeapSort();
        // Hay que implementarlo en la subclase
        void sort(const std::vector<Key>& seq, unsigned i) const;
};

template<class Key>
HeapSort<Key>::HeapSort() {}

template<class Key>
HeapSort<Key>::~HeapSort() {}

template<class Key>
void HeapSort<Key>::sort(const std::vector<Key>& seq, unsigned i) const {
    std::cout << "\nMetodo de HeapSort...\n";
    std::cout << "\nSeq: \e[31m";
        for(auto value: seq) {
            std::cout << "\t" << value;
        }
    std::cout << "\e[0m";
    ordenacionHeapSort(seq, i);
}

#endif //HEAPSORT_H