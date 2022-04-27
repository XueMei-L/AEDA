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