#ifndef NODE_B_H
#define NODE_B_H

#include <cstdio>
#include <ostream>

template<class Key>
class NodoB {
private:
	Key data_;
	NodoB* izq_;
	NodoB* dcho_;
    // int bal_;
public:
	NodoB();
	NodoB(const Key, NodoB<Key>*, NodoB<Key>*);
	~NodoB();
	NodoB*& get_izq(void);
	NodoB*& get_der(void);
	Key& get_data(void);

    void set_data(const Key data);
    // std::ostream& write (ostream& os) const
	// int& bal(void);
};

// Construtor por defecto
template<class Key>
NodoB<Key>::NodoB(void): data_(), izq_(nullptr), dcho_(nullptr) {}

// Constructor parametrizado
template<class Key>
NodoB<Key>::NodoB(const Key data, NodoB<Key>* izq, NodoB<Key>* der): data_(data), izq_(nullptr), dcho_(nullptr) {}

// Destructor
template<class Key>
NodoB<Key>::~NodoB(void) {}

// Getters
template<class Key>
NodoB<Key>*& NodoB<Key>::get_der(void) {
	return dcho_;
}

template<class Key>
NodoB<Key>*& NodoB<Key>::get_izq(void) {
	return izq_;
}

template<class Key>
Key& NodoB<Key>::get_data(void)  {
	return data_;
}

// Setters
template<class Key>
void NodoB<Key>::set_data(Key data)  {
	data_ = data;
}

#endif //NODE_B_H