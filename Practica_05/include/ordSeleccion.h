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
        std::vector<Key> sort(const std::vector<Key>& seq, unsigned i) const;
};

template<class Key>
Seleccion<Key>::Seleccion() {}

template<class Key>
Seleccion<Key>::~Seleccion() {}

template<class Key>
std::vector<Key> Seleccion<Key>::sort(const std::vector<Key>& seq, unsigned i) const {
    std::cout << "\nMetodo de seleccion...\n";
    ordenacionSeleccion(seq, i);

    return seq;
}

#endif //SELECCION_H