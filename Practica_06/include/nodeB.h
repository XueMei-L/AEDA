#pragma once

#include <cstdio>
#include <ostream>

template<class Key>
class nodo {
private:
	Key data_;
	nodo* izq_;
	nodo* der_;
    // int bal_;
public:
	nodo();
	nodo(Key);
	~nodo();
	nodo*& get_izq(void);
	nodo*& get_der(void);
	Key& get_data(void);

    void set_data(Key data);
    // std::ostream& write (ostream& os) const
	// int& bal(void);
};

// Construtor por defecto
template<class Key>
nodo<Key>::nodo(void): data_(), izq_(nullptr), der_(nullptr) {}

// Constructor parametrizado
template<class Key>
nodo<Key>::nodo(Key dato): data_(dato), izq_(nullptr), der_(nullptr) {}

// Destructor
template<class Key>
nodo<Key>::~nodo(void) {}

// Getters
template<class Key>
nodo<Key>*& nodo<Key>::get_der(void) {
	return der_;
}

template<class Key>
nodo<Key>*& nodo<Key>::get_izq(void) {
	return izq_;
}

template<class Key>
Key& nodo<Key>::get_data(void)  {
	return data_;
}

// Setters
template<class Key>
void nodo<Key>::set_data(Key data)  {
	data_ = data;
}

/* Imprime el nodo formateado */
// std::ostream& write (ostream& os) const
// {
//     // Si el nodo está vacío...
//     if (this == NULL){
//         os << "[.]";
//     }
//     // Si el nodo NO está vacío...
//     else{
//         os << "[";
//         dato_.write(os);
//         cout << "]";
//     }
//     return os;
// }


// template<class tipo_dato>
// int& nodo<tipo_dato>::bal(void){
// 	return bal_;
// }