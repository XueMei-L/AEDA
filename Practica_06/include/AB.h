#ifndef AB_H
#define AB_H

#include <cstdio>
#include <iostream>
#include "./nodoB.h"

template<class Key>
class AB {

public:
	AB();
	~AB();
	virtual bool insert(const Key& k) = 0;
	virtual bool search(const Key& k) const = 0;
	virtual void remove(const Key& k) = 0;
	virtual void showAB() = 0;
	void inorden() const;
	NodoB<Key>* get_root_() const;
	void set_root_(NodoB<Key>* raiz);
private:
	NodoB<Key>* root_;
	void inordenRecursivo(NodoB<Key>* nodo) const;
};


template<class Key>
AB<Key>::AB() {}

template<class Key>
AB<Key>::~AB() {}

template<class Key>
NodoB<Key>*
AB<Key>::get_root_() const {
	return root_;
}

template<class Key>
void
AB<Key>::set_root_(NodoB<Key>* raiz) {
	root_ = raiz;
}

template<class Key>
void
AB<Key>::inorden() const {
	std::cout << "inorden\n";
	inordenRecursivo(root_);
}

template<class Key>
void
AB<Key>::inordenRecursivo(NodoB<Key>* nodo) const {
	if (nodo != NULL) {
		inordenRecursivo(nodo->get_izq());
		std::cout << nodo->get_data();
		inordenRecursivo(nodo->get_der());
  	}
}

#endif //AB_H