#ifndef LIST_H
#define LIST_H

#include "sequence.h"
#include <algorithm>
#include <list>

template<class Key>
class List: public Sequence<Key>
{
    private:
        std::list<Key*> list_;

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
bool List<Key>::search(const Key& k) const 
{
    // std::list<int>::iterator it;
    
    // if(list_.empty()) {
    //     return false;
    // }
    // it = std::find(list_.begin(), list_.end(), k);

    // if(it != list_.end()) {
    //     return true;
    // }
    // for(it = list_.begin(); it != list_.end(); it++) {
    //     if(it-> == k) {
    //         return true;
    //     }
    // }
    return false; 

}

template<class Key>
bool List<Key>::insert(const Key& k)
{ 
    list_.push_back(new Key(k));
    return true; 
}

template<class Key>
bool List<Key>::isFull() const 
{ 
    return false; 
} 


#endif //LIST_H