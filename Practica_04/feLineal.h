#ifndef FELINEAL_H
#define FELINEAL_H

#include "fdModule.h"

template<class Key>
class feLineal: public FunctionExploracion<Key>
{
private:
    /* data */
public:

    feLineal();
    ~feLineal();

    //Metodo derivado
    unsigned operator()(const Key& k, unsigned i) const;
};

template<class Key>
feLineal<Key>::feLineal():feLineal(){}


template<class Key>
feLineal<Key>::~feLineal(){}


template<class Key>
unsigned feLineal<Key>::operator()(const Key& k, unsigned i) const {
    return i;
}

#endif //FELINEAL_H