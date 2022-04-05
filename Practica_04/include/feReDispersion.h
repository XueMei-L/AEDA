#ifndef FE_REDISPERSION_H
#define FE_REDISPERSION_H

#include <stdlib.h>
#include <iostream>
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

    // srand(i+k);
    // switch (rand()%3)
    // {
    //     case 0: feRedispersion_ = new fdModule<Key>*(nCeldas_);
    //         std::cout << "feRedispersion_Module";
    //     break;
    //     case 1: 
    //         feRedispersion_ = new fdSum<Key>*(nCeldas_);
    //         std::cout << "feRedispersion_Sum";
    //     break;
    //     case 2: feRedispersion_ = new fdPseudorandom<Key>* (nCeldas_);
    //         std::cout << "feRedispersion_Pseudorandom";
    //     break;
    // }
    // return ((*feRedispersion_)(k)+i) % nCeldas_;
}

#endif //FE_REDISPERSION_H