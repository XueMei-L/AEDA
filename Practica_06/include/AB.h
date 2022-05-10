#ifndef AB_H
#define AB_H

#include <cstdio>
#include <ostream>
#include "./nodoB.h"

template<class Key>
class AB {

public:
	virtual bool insert(const Key& k) = 0;
	virtual bool search(const Key& k) const = 0;
	virtual void remove(const Key& k) = 0;
	virtual void showAB() = 0;
	void inorden() const;

private:
	NodoB<Key>* root_;
};

#endif //AB_H