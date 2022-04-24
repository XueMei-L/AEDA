#ifndef SELECCION_H
#define SELECCION_H

#include <iostream>
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
        unsigned sort(const Key& k, unsigned i) const;
};

template<class Key>
Seleccion<Key>::Seleccion() {}

template<class Key>
Seleccion<Key>::~Seleccion() {}

template<class Key>
unsigned Seleccion<Key>::sort(const Key& k, unsigned i)const {
    std::cout << "Metodo de seleccion... \nLlamar a metodo seleccion()... \n";
    // ordenacionSeleccion(k, i);
}

#endif //SELECCION_H