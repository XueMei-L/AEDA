#ifndef FD_MODULE_H
#define FD_MODULE_H

#include "dispersionFunction.h"
#include <iostream>

template<class Key>
class fdModule: public DispersionFunction<Key>
{
private:
    /* data */
    unsigned tableSize;
public:

    fdModule(const unsigned n);
    ~fdModule();
    unsigned operator()(const Key& k) const;

};

template<class Key>
fdModule<Key>::fdModule(const unsigned n): tableSize(n){}

template<class Key>
fdModule<Key>::~fdModule(){}

template<class Key>
unsigned fdModule<Key>::operator()(const Key& k) const {
    std::cout << "module";
    return k % tableSize;
}

#endif //FD_MODULE_H