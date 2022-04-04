#ifndef feCuadratica_H
#define feCuadratica_H

#include "explorationFunction.h"

template<class Key>
class feCuadratica: public ExplorationFunction<Key>
{
private:
    /* data */
public:

    feCuadratica();
    ~feCuadratica();

    //Metodo derivado
    unsigned operator()(const Key& k, unsigned i) const;
};

template<class Key>
feCuadratica<Key>::feCuadratica(){}


template<class Key>
feCuadratica<Key>::~feCuadratica(){}


template<class Key>
unsigned feCuadratica<Key>::operator()(const Key& k, unsigned i) const {
    //posicion cuadratica
    return i * i;
}

#endif //feCuadratica_H