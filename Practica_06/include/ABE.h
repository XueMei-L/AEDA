#ifndef ABE_H
#define ABE_H

#include <queue>
#include <iostream>
#include "./nodoB.h"
#include "./AB.h"

template<class Key>
class ABE : public AB<Key> {

public:
    ABE();
    ~ABE();
    bool insert(const Key& k);
	void seach(const Key& k) const;
	void remove(const Key& k);
	void inorden() const;
	// std::ostream& operator<<(ostream& os, const Date& dt);
    const int SizeBranch(NodoB<Key>* node);
    void InsertBalanceB(const Key data, NodoB<Key>* node);
    void showAB();
private:
	NodoB<Key>* root_;
};

template <class Key>
ABE<Key>::ABE() : root_(nullptr){}

template <class Key>
ABE<Key>::~ABE() {}

//  Insercion de arbol binario
template <class Key>
bool
ABE<Key>::insert(const Key& data) {
    std::cout << "insert";
  if (root_ == nullptr) {
    root_ = new NodoB<Key>(data, NULL, NULL);
  } else {
    InsertBalanceB(data, root_);
  }
  return true;
}

template<class Key>
void
ABE<Key>::InsertBalanceB(const Key data, NodoB<Key>* node) {
    std::cout << "insertbalanceB";
  if (SizeBranch(node->izq_) <= SizeBranch(node->der_)) {
    if (node->izq_ != NULL) {
      InsertBalanceB(data, node->izq_);
    } else {
      node->izq_ = new NodoB<Key>(data, NULL, NULL);
    }
  } else {
    if (node->der_ != NULL) {
      InsertBalanceB(data, node->der_);
    } else {
      node->der_ = new NodoB<Key>(data, NULL, NULL);
    }
  }
}


template <class Key>
const int
ABE<Key>::SizeBranch(NodoB<Key>* node) {
  if (node == NULL) return 0;
  return (1 + SizeBranch(node->izq_) +
         SizeBranch(node->der_));
}


template <class Key>
void
ABE<Key>::showAB() {
    std::cout << "here";
    if(root_ == nullptr) {
        std::cout << "Arbol vacio" << std::endl;
        std::cout << "Niver 0: [.]\n";
        return;
    }
    // std::queue<NodoB<Key>*> Q;
    // std::queue<int> Q1;
    // NodoB<Key>* nodo;
    // int aux = 0;
    // int level{0}, current_level{0}; 
    // std::cout << "Nivel " << level << ": ";
    // Q.push(root_);
    // Q1.push(0);

    // while (!Q.empty()) {
    //     nodo = Q.front();
    //     Q.pop();
    //     level = Q1.front();
    //     Q1.pop();
    //     if (level > current_level) {
    //     current_level = level;
    //     std::cout << "\n";
    //     std::cout << "Nivel " << current_level << ": ";
    //     }
    //     if (nodo != NULL) {
    //     std::cout << " ["<< nodo->dato_ << "]";
    //     Q.push(nodo->izq_);
    //     Q1.push(level + 1);
    //     Q.push(nodo->der_);
    //     Q1.push(level + 1);
    //     } else {
    //     // subarbol vacio
    //     std::cout << " [.] ";
    //     }
    // }
    // std::cout << std::endl;
}


template <class Key>
void
ABE<Key>::remove(const Key& k) { 
    throw std::__throw_bad_function_call;
}

#endif //ABE_H