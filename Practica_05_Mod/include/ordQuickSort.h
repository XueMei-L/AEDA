/********************************************************************
* AUTOR: XueMei Lin
* EMAIL: alu0101225845@ull.edu.es
* UNIVERSIDAD: Universidad de La Laguna
* ASIGNATURA: Algoritmos y estructura de datos avanzadas
* VERSION: 1.0
* PRACTICA: 05
* TITUTLO: Practica 05 Ordenacion
* DESCRIPTION: fichero .h que include sort del algoritmo QuickSort
* COMPILACION: make
*              make clean (para eliminar)
* *****************************************************************/

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <vector>
#include "ordenacion.h"
// #include "MetodoOrdenacion.h"

template<class Key>
class QuickSort: public Ordenacion<Key>
{
    private:
        /* data */
    public:
        QuickSort();
        ~QuickSort();
        // Hay que implementarlo en la subclase
        void sort(const std::vector<Key>& seq, unsigned i) const;
};

template<class Key>
QuickSort<Key>::QuickSort() {}

template<class Key>
QuickSort<Key>::~QuickSort() {}

template<class Key>
void QuickSort<Key>::sort(const std::vector<Key>& seq, unsigned i) const {
    std::cout << "\nMetodo de QuickSort...\n";
    std::cout << "\nSeq: \e[31m";
        for(auto value: seq) {
            std::cout << "\t" << value;
        }
    std::cout << "\e[0m";
    ordenacionQuickSort(seq, 0, i-1);
}

#endif //QUICKSORT_H