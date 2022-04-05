#ifndef feDoble_H
#define feDoble_H

#include "explorationFunction.h"
#include "dispersionFunction.h"

template<class Key>

class feDoble: public ExplorationFunction<Key>
{
private:
    DispersionFunction<Key>* fdDoble_;       //funcion de dispersion
    int nCeldas_;
public:

    feDoble(int);
    ~feDoble();

    //Metodo derivado
    unsigned operator()(const Key& k, unsigned i) const;
};

template<class Key>
feDoble<Key>::feDoble(int numCeldas):nCeldas_(numCeldas)
{
    // fdDoble_ = new fdModule<Key>(numCeldas);
}


template<class Key>
feDoble<Key>::~feDoble(){}


template<class Key>
unsigned feDoble<Key>::operator()(const Key& k, unsigned i) const {
    // return *fdDoble_(k) * i;
}

#endif //feDoble_H