#ifndef LIST_H
#define LIST_H

#include "sequence.h"
// #include <algorithm>
#include <list>
#include "node.h"
#include "../src/Node.cc"

template<class Key>
class List: public Sequence<Key>
{
    private:
        std::list<Key*> list_;
        Node<Key> *m_head;
        int m_num_nodes;
    public:
        List();
        ~List();

        bool search(const Key& k) const;
        bool insert(const Key& k);
        bool isFull() const; 
};

template<class Key>
List<Key>::List() {
    m_num_nodes = 0;
    m_head = NULL;
}

template<class Key>
List<Key>::~List() {}

template<class Key>
bool List<Key>::search(const Key& k) const 
{
    Node<Key> *temp = m_head;

    while(temp) {
        if(temp->data == k) {
            return true;
        }
        temp = temp->next;
    }
    return false;

}

template<class Key>
bool List<Key>::insert(const Key& k)
{ 
    bool check;
    check = search(k);
    if(check == true) {
        return false;
    }else {
        Node<Key> *new_node = new Node<Key> (k);
        Node<Key> * temp = m_head;

        // si es no existe mi cabecera, el nodo actual es el primer nodo
        if(!m_head) {
            m_head = new_node;
        }else {
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    m_num_nodes++;
    }
    // list_.push_back(new Key(k));
    return true; 
}

template<class Key>
bool List<Key>::isFull() const 
{ 
    return false; 
} 

#endif //LIST_H