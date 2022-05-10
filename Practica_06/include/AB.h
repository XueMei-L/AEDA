#ifndef AB_H
#define AB_H

#include <cstdio>
#include <iostream>
#include "./nodoB.h"

template<class Key>
class AB {

public:
	// AB();
	// ~AB();
	virtual bool insert(const Key& k) = 0;
	virtual bool search(const Key& k) const = 0;
	virtual void remove(const Key& k) = 0;
	virtual void showAB() = 0;
	virtual void callInorden() = 0;
	// void inorden(NodoB<Key>* leap) const;

private:
	NodoB<Key>* root_;
};


// template<class Key>
// AB<Key>::AB() {}

// template<class Key>
// AB<Key>::~AB() {}

// template<class Key>
// void
// AB<Key>::inorden(NodoB<Key>* leap) const {
// 	if (leap != NULL) {
//     inorden(leap->get_izq());
// 	std::cout << leap->get_data();
//     // tratar(a);                                 //Realiza una operación en nodo
//     inorden(leap->get_der());
//   }
// }

#endif //AB_H