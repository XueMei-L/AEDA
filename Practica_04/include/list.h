#ifndef LIST_H
#define LIST_H

#include "sequence.h"

template<class Key>
class List: public Sequence<Key>
{
    
    public:
        List();
        ~List();

        bool search(const Key& k) const;
        bool insert(const Key& k);
        bool isFull() const; 
};

template<class Key>
List<Key>::List() {}

template<class Key>
List<Key>::~List() {}

template<class Key>
bool List<Key>::search(const Key& k) const { return true; }

template<class Key>
bool List<Key>::insert(const Key& k) { return true; }

template<class Key>
bool List<Key>::isFull() const 
{ 
    return false; 
} 

#endif //LIST_H