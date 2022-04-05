#ifndef FD_PSEUDORANDO_H
#define FD_PSEUDORANDO_H

#include <stdlib.h>
#include "dispersionFunction.h"

template<class Key>
class fdPseudorandom: public DispersionFunction<Key>
{
private:
    /* data */
    unsigned tableSize_;
public:

    fdPseudorandom(const unsigned n);
    ~fdPseudorandom();

    unsigned operator()(const Key& k) const;
};

template<class Key>
fdPseudorandom<Key>::fdPseudorandom(const unsigned n): tableSize_(n){}

template<class Key>
fdPseudorandom<Key>::~fdPseudorandom(){}

template<class Key>
unsigned fdPseudorandom<Key>::operator()(const Key& k) const {
    srand(k);
    return rand() % tableSize_;
    // return srand(k);
}

#endif //FD_PSEUDORANDO_H