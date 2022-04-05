#ifndef FD_SUM_H
#define FD_SUM_H

#include "dispersionFunction.h"

template<class Key>
class fdSum: public DispersionFunction<Key>
{
private:
    /* data */
    unsigned tableSize;
public:

    fdSum(const unsigned n);
    ~fdSum();
    unsigned operator()(const Key& k) const;

};

template<class Key>
fdSum<Key>::fdSum(const unsigned n): tableSize(n){}

template<class Key>
fdSum<Key>::~fdSum(){}

template<class Key>
unsigned fdSum<Key>::operator()(const Key& k) const {
    // Sumatorio de las posiciones dentro de K y mod size;

    int d = 0;
    int x = k;

    while(x > 0) {
        int y = x % 10;
        d += y;
        x /= 10; 
    }

    return (d % tableSize);
}

#endif //FD_SUM_H