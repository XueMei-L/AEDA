#ifndef BLOCK_H
#define BLOCK_H

#include "sequence.h"

template<class Key>
class Block: public Sequence<Key>
{
    private:
        int blockSize_;
    public:
        Block(int);
        ~Block();

        bool search(const Key& k) const;
        bool insert(const Key& k);
        bool isFull() const; 
};

template<class Key>
Block<Key>::Block(int blocksize) : blockSize_(blocksize){}

template<class Key>
Block<Key>::~Block(){}

template<class Key>
bool Block<Key>::search(const Key& k) const { return true; }

template<class Key>
bool Block<Key>::insert(const Key& k){ return true; }

template<class Key>
bool Block<Key>::isFull() const 
{
    return false;
}

#endif //BLOCK_H