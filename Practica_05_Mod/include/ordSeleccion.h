/********************************************************************
* AUTOR: XueMei Lin
* EMAIL: alu0101225845@ull.edu.es
* UNIVERSIDAD: Universidad de La Laguna
* ASIGNATURA: Algoritmos y estructura de datos avanzadas
* VERSION: 1.0
* PRACTICA: 05
* TITUTLO: Practica 05 Ordenacion
* DESCRIPTION: fichero .h que include sort del algoritmo Seleccion
* COMPILACION: make
*              make clean (para eliminar)
* *****************************************************************/

#ifndef SELECCION_H
#define SELECCION_H

#include <iostream>
#include <vector>
#include "ordenacion.h"
#include "MetodoOrdenacion.h"

template<class Key>
class Seleccion: public Ordenacion<Key>
{
    private:
        /* data */
    public:
        Seleccion();
        ~Seleccion();
        // Hay que implementarlo en la subclase
        void sort(const std::vector<Key>& seq, unsigned i) const;
};

template<class Key>
Seleccion<Key>::Seleccion() {}

template<class Key>
Seleccion<Key>::~Seleccion() {}

template<class Key>
void Seleccion<Key>::sort(const std::vector<Key>& seq, unsigned i) const {
    std::cout << "\nMetodo de Seleccion...\n";
    std::cout << "\nSeq: \e[31m";
        for(auto value: seq) {
            std::cout << "\t" << value;
        }
    std::cout << "\e[0m";
    ordenacionSeleccion(seq, i);
}

#endif //SELECCION_H