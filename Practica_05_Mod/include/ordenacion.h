/********************************************************************
* AUTOR: XueMei Lin
* EMAIL: alu0101225845@ull.edu.es
* UNIVERSIDAD: Universidad de La Laguna
* ASIGNATURA: Algoritmos y estructura de datos avanzadas
* VERSION: 1.0
* PRACTICA: 05
* TITUTLO: Practica 05 Ordenacion
* DESCRIPTION: La clase abstracta Ordenacion
* COMPILACION: make
*              make clean (para eliminar)
* *****************************************************************/

#ifndef ORDENACION_H
#define ORDENACION_H

#include <vector>

template<class Key>
class Ordenacion {
    private:
        /* data */
    public:
        // Hay que implementarlo en la subclase
        virtual void sort(const std::vector<Key>& seq, unsigned i) const = 0;
};

#endif //ORDENACION_H