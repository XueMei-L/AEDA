#ifndef FE_REDISPERSION_H
#define FE_REDISPERSION_H

#include "explorationFunction.h"

template<class Key>

class feRedispersion: public ExplorationFunction<Key>
{
private:
    feRedispersion<Key>* feRedispersion_;       //funcion de dispersion
    int nCeldas_;
public:

    feRedispersion(int);
    ~feRedispersion();

    //Metodo derivado
    unsigned operator()(const Key& k, unsigned i) const;
};

template<class Key>
feRedispersion<Key>::feRedispersion(int numCeldas): nCeldas_(numCeldas)
{
    // feRedispersion_ = new dispersionPrima<Key>(nCeldas);
}

template<class Key>
feRedispersion<Key>::~feRedispersion(){}


template<class Key>
unsigned feRedispersion<Key>::operator()(const Key& k, unsigned i) const {
    // return *feRedispersion_(k);
}

#endif //FE_REDISPERSION_H