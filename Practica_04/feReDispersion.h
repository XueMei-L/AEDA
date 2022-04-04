#ifndef feRedispersion_H
#define feRedispersion_H

#include "fdModule.h"

template<class Key>

class feRedispersion: public FunctionExploracion<Key>
{
private:
    feRedispersion<Key>*   feRedispersion_;       //funcion de dispersion
    int nCeldas_;
public:

    feRedispersion();
    ~feRedispersion();

    //Metodo derivado
    unsigned operator()(const Key& k, unsigned i) const;
};

template<class Key>
feRedispersion<Key>::feRedispersion():feRedispersion(int numCeldas): nCeldas_(numCeldas)
{
    // feRedispersion_ = new dispersionPrima<Key>(nCeldas);
}


template<class Key>
feRedispersion<Key>::~feRedispersion(){}


template<class Key>
unsigned feRedispersion<Key>::operator()(const Key& k, unsigned i) const {
    return *feRedispersion_(k);
}

#endif //feRedispersion_H