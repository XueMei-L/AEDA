#ifndef AB_H
#define AB_H

#include <cstdio>
#include <queue>
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
	Key& operator[](const Key& k);
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


// Modificacion
template<class Key>
Key&
AB<Key>::operator[](const Key& k) {
	Key result;
	std::queue<NodoB<Key>*> Q;
	NodoB<Key>* nodo;
	Q.push(root_);
	// std::cout << k.first;
	// std::cout << k.second;
	
	while (!Q.empty()) {
		nodo = Q.front();
		Q.pop();
		if (nodo != NULL) {
			if (nodo->get_data() == k ) {
				std::cout << "Encontrado\n";
				result = nodo->get_data();
				std::cout << "[" << k.second << "]\n";
				return result;
			}
			Q.push(nodo->get_izq());
			Q.push(nodo->get_der());
		}
	}

	// return k;
}

#endif //AB_H