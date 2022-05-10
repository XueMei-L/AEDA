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
    bool search(const Key& k) const;
    void remove(const Key& k);
    void showAB();
    void inorden() const;
	// std::ostream& operator<<(ostream& os, const Date& dt);
    const int SizeBranch(NodoB<Key>* node);
    void InsertBalanceB(const Key data, NodoB<Key>* node);
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
  if(search(data)) {
    std::cout << "Can not insert the same value to the Binary Tree.\n";
    return false;
  } else {
    if (root_ == nullptr) {
      root_ = new NodoB<Key>(data, NULL, NULL);
    } else {
      InsertBalanceB(data, root_);
    }
    return true;
  }
  return true;
}

template<class Key>
void
ABE<Key>::InsertBalanceB(const Key data, NodoB<Key>* node) {
  if (SizeBranch(node->get_izq()) <= SizeBranch(node->get_der())) {
    if (node->get_izq() != NULL) {
      InsertBalanceB(data, node->get_izq());
    } else {
      node->get_izq() = new NodoB<Key>(data, NULL, NULL);
    }
  } else {
    if (node->get_der() != NULL) {
      InsertBalanceB(data, node->get_der());
    } else {
      node->get_der() = new NodoB<Key>(data, NULL, NULL);
    }
  }
}

template <class Key>
bool 
ABE<Key>::search(const Key& k) const {
  std::queue<NodoB<Key>*> Q;
  NodoB<Key>* nodo;
  Q.push(root_);

  while (!Q.empty()) {
    nodo = Q.front();
    Q.pop();
    if (nodo != NULL) {
      if (nodo->get_data() == k ) {
        return true;
      }
      Q.push(nodo->get_izq());
      Q.push(nodo->get_der());
    }
  }
  return false;
}

template <class Key>
const int
ABE<Key>::SizeBranch(NodoB<Key>* node) {
  if (node == NULL) return 0;
  return (1 + SizeBranch(node->get_izq()) +
         SizeBranch(node->get_der()));
}


template <class Key>
void
ABE<Key>::showAB() {
    // std::cout << "ShowAB\n";
    if(root_ == nullptr) {
        std::cout << "Arbol vacio" << std::endl;
        std::cout << "Niver 0: [.]\n";
        return;
    }
    std::queue<NodoB<Key>*> Q;
    std::queue<int> Q1;
    NodoB<Key>* nodo;
    int aux = 0;
    int level{0}, current_level{0}; 
    std::cout << "Nivel " << level << ": ";
    Q.push(root_);
    Q1.push(0);

    while (!Q.empty()) {
      nodo = Q.front();
      Q.pop();
      level = Q1.front();
      Q1.pop();
      if (level > current_level) {
        current_level = level;
        std::cout << "\n";
        std::cout << "Nivel " << current_level << ": ";
      }
      if (nodo != NULL) {
        std::cout << " ["<< nodo->get_data() << "]";
        Q.push(nodo->get_izq());
        Q1.push(level + 1);
        Q.push(nodo->get_der());
        Q1.push(level + 1);
      } else {
        std::cout << " [.] ";
      }
    }
    std::cout << std::endl;
}

template <class Key>
void
ABE<Key>::remove(const Key& k) { 
  try {
    if(k != -1) {
      std::cerr << "The remove function is not implemented." << std::endl; 
    }
  } catch (std::exception& e){ 
    std::cerr << "The remove function is not implemented." << std::endl; 
  }
}

#endif //ABE_H