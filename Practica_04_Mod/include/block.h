#ifndef BLOCK_H
#define BLOCK_H

#include "sequence.h"
#include <vector>
template<class Key>
class Block: public Sequence<Key>
{
    private:
        int blockSize_;
        std::vector<Key*> vBlock_;
    public:
        Block();
        Block(int);
        ~Block();

        bool search(const Key& k) const;
        bool insert(const Key& k);
        bool isFull() const; 
};

template<class Key>
Block<Key>::Block()
{
    // for(int i = 0; i < blocksize_; i++) {
    //     vBlock_.push_back()
    // }
}

template<class Key>
Block<Key>::Block(int blocksize) : blockSize_(blocksize)
{
    // for(int i = 0; i < blocksize_; i++) {
    //     vBlock_.push_back()
    // }
}

template<class Key>
Block<Key>::~Block(){}

template<class Key>
bool Block<Key>::search(const Key& k) const
{ 
    for(int i = 0; i < blockSize_; i++) {
        if(*vBlock_[i] == k) {
            return true;
        }
    }
    return false; 
}

template<class Key>
bool Block<Key>::insert(const Key& k)
{ 
    if(isFull() == false) {
        std::cout << "sss";
        vBlock_.push_back(new Key(k));
        return true;
    }
    return true; 
}

template<class Key>
bool Block<Key>::isFull() const 
{
    if(vBlock_.size() == blockSize_) 
    {
        return true;
    }
    return false;
}

#endif //BLOCK_H