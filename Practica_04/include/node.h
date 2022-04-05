/**
 * @brief Implementacion de un nodo que va 
 * a utilizar la clase Lista
*/

#ifndef NODE_H
#define NODE_H
 
#include <iostream>
  
template<class Key>
class Node {
  public:
    Node();
    Node(Key);
    ~Node();
 
    Node *next;
    Key data;
 
    void delete_all();
    void print();
};
 
#endif // NODE_H