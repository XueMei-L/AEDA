#include "../include/node.h"
 
// Constructor por defecto
template<class Key>
Node<Key>::Node() {
    data = NULL;
    next = NULL;
}
 
// Constructor por parámetro
template<class Key>
Node<Key>::Node(Key data_) {
    data = data_;
    next = NULL;
}
 
// Eliminar todos los Nodos
template<class Key>
void 
Node<Key>::delete_all() {
    if (next)
      next->delete_all();
    delete this;
}
 
// Imprimir un Nodo
template<class Key>
void 
Node<Key>::print() {
    //cout << "Node-> " << "Dato: " << dato << " Direcion: " << this << " Siguiente: " << next << endl;
    std::cout << data << "-> ";
}
 
template<typename Key>
Node<Key>::~Node() {}