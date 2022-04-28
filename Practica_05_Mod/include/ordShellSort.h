/********************************************************************
* AUTOR: XueMei Lin
* EMAIL: alu0101225845@ull.edu.es
* UNIVERSIDAD: Universidad de La Laguna
* ASIGNATURA: Algoritmos y estructura de datos avanzadas
* VERSION: 1.0
* PRACTICA: 05
* TITUTLO: Practica 05 Ordenacion
* DESCRIPTION: fichero .h que include sort del algoritmo ShellSort
* COMPILACION: make
*              make clean (para eliminar)
* *****************************************************************/

#ifndef SHELLSORT_H
#define SHELLSORT_H

#include <iostream>
#include <vector>
#include "ordenacion.h"
// #include "MetodoOrdenacion.h"

template<class Key>
class ShellSort: public Ordenacion<Key>
{
    private:
        /* data */
    public:
        ShellSort();
        ~ShellSort();
        // Hay que implementarlo en la subclase
        void sort(const std::vector<Key>& seq, unsigned i) const;
};

template<class Key>
ShellSort<Key>::ShellSort() {}

template<class Key>
ShellSort<Key>::~ShellSort() {}

template<class Key>
void ShellSort<Key>::sort(const std::vector<Key>& seq, unsigned i) const {
    std::cout << "\nMetodo de ShellSort...\n";
    double alfa;
    std::cout << "Introduzca el valor de alfa( 0 < alfa < 1 ):";
    std::cin >> alfa;
    std::cout << "\nSeq: \e[31m";
        for(auto value: seq) {
            std::cout << "\t" << value;
        }
    std::cout << "\e[0m";
    ordenacionShellSort(seq, i, alfa);
}

#endif //SHELLSORT_H