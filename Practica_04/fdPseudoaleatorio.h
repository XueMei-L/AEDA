#ifndef FD_PSEUDORANDO
#define FD_PSEUDORANDO

#include <stdlib.h>
#include "dispersionFunction.h"

template<class Key>
class fdPseudorandom: public DispersionFunction<Key>
{
private:
    /* data */
    unsigned tableSize;
public:

    fdPseudorandom(const unsigned n);
    ~fdPseudorandom();
    unsigned operator()(const Key& k) const;

};

template<class Key>
fdPseudorandom<Key>::fdPseudorandom(const unsigned n): tableSize(n){}

template<class Key>
fdPseudorandom<Key>::~fdPseudorandom(){}

template<class Key>
unsigned fdPseudorandom<Key>::operator()(const Key& k) const {
    return srand(k);
}

#endif //FD_PSEUDORANDO