#ifndef NODE_B_H
#define NODE_B_H

#include <cstdio>
#include <ostream>

template<class Key>
class NodoB {
private:
	Key data_;
	NodoB* izq_;
	NodoB* der_;
    // int bal_;
public:
	NodoB();
	NodoB(Key);
	~NodoB();
	NodoB*& get_izq(void);
	NodoB*& get_der(void);
	Key& get_data(void);

    void set_data(Key data);
    // std::ostream& write (ostream& os) const
	// int& bal(void);
};

// Construtor por defecto
template<class Key>
NodoB<Key>::NodoB(void): data_(), izq_(nullptr), der_(nullptr) {}

// Constructor parametrizado
template<class Key>
NodoB<Key>::NodoB(Key dato): data_(dato), izq_(nullptr), der_(nullptr) {}

// Destructor
template<class Key>
NodoB<Key>::~NodoB(void) {}

// Getters
template<class Key>
NodoB<Key>*& NodoB<Key>::get_der(void) {
	return der_;
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

/* Imprime el NodoB formateado */
// std::ostream& write (ostream& os) const
// {
//     // Si el NodoB está vacío...
//     if (this == NULL){
//         os << "[.]";
//     }
//     // Si el NodoB NO está vacío...
//     else{
//         os << "[";
//         dato_.write(os);
//         cout << "]";
//     }
//     return os;
// }


// template<class tipo_dato>
// int& NodoB<tipo_dato>::bal(void){
// 	return bal_;
// }


#endif //NODE_B_H