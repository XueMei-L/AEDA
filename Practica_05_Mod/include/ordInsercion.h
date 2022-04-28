/********************************************************************
* AUTOR: XueMei Lin
* EMAIL: alu0101225845@ull.edu.es
* UNIVERSIDAD: Universidad de La Laguna
* ASIGNATURA: Algoritmos y estructura de datos avanzadas
* VERSION: 1.0
* PRACTICA: 05
* TITUTLO: Practica 05 Ordenacion
* DESCRIPTION: fichero .h que include sort del algoritmo Inserccion
* COMPILACION: make
*              make clean (para eliminar)
* *****************************************************************/

#ifndef INSERCION_H
#define INSERCION_H

#include <iostream>
#include <vector>
#include "ordenacion.h"
// #include "MetodoOrdenacion.h"

template<class Key>
class Insercion: public Ordenacion<Key>
{
    private:
        /* data */
    public:
        Insercion();
        ~Insercion();
        // Hay que implementarlo en la subclase
        void sort(const std::vector<Key>& seq, unsigned i) const;
};

template<class Key>
Insercion<Key>::Insercion() {}

template<class Key>
Insercion<Key>::~Insercion() {}

template<class Key>
void Insercion<Key>::sort(const std::vector<Key>& seq, unsigned i) const {
    std::cout << "\nMetodo de Insercion...\n";
    std::cout << "\nSeq: \e[31m";
        for(auto value: seq) {
            std::cout << "\t" << value;
        }
    std::cout << "\e[0m";
    ordenacionInsercion(seq, i);
}

#endif //INSERCION_H